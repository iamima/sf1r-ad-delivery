#include "CollectionTask.h"

#include <controllers/CollectionHandler.h>
#include <common/CollectionManager.h>
#include <common/XmlConfigParser.h>

#include <bundles/index/IndexTaskService.h>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/filesystem.hpp>
namespace bfs = boost::filesystem;
namespace bfs3 = boost::filesystem3;

namespace sf1r
{

void RebuildTask::startTask()
{
    task_type task = boost::bind(&RebuildTask::doTask, this);
    asyncJodScheduler_.addTask(task);
}

void RebuildTask::doTask()
{
    if (isRunning_)
    {
        LOG(ERROR) << "RebuildTask is running!" ;
        return;
    }

    LOG(INFO) << "## start RebuildTask for " << collectionName_;
    isRunning_ = true;

    std::string collDir;
    std::string rebuildCollDir;
    std::string rebuildCollBaseDir;
    std::string configFile = SF1Config::get()->getCollectionConfigFile(collectionName_);

    {
    // check collection resource
    CollectionManager::MutexType* collMutex = CollectionManager::get()->getCollectionMutex(collectionName_);
    CollectionManager::ScopedReadLock collLock(*collMutex);
    CollectionHandler* collectionHandler = CollectionManager::get()->findHandler(collectionName_);
    if (!collectionHandler || !collectionHandler->indexTaskService_)
    {
        LOG(ERROR) << "Not found collection: " << collectionName_;
        isRunning_ = false;
        return;
    }
    boost::shared_ptr<DocumentManager> documentManager = collectionHandler->indexTaskService_->getDocumentManager();
    CollectionPath& collPath = collectionHandler->indexTaskService_->getCollectionPath();
    collDir = collPath.getCollectionDataPath() + collPath.getCurrCollectionDir();

    // start collection for rebuilding
    LOG(INFO) << "## startCollection for rebuilding: " << rebuildCollectionName_;
    if (!CollectionManager::get()->startCollection(rebuildCollectionName_, configFile, true))
    {
        LOG(ERROR) << "Collection for rebuilding already started: " << rebuildCollectionName_;
        isRunning_ = false;
        return;
    }
    CollectionManager::MutexType* recollMutex = CollectionManager::get()->getCollectionMutex(rebuildCollectionName_);
    CollectionManager::ScopedReadLock recollLock(*recollMutex);
    CollectionHandler* rebuildCollHandler = CollectionManager::get()->findHandler(rebuildCollectionName_);
    LOG(INFO) << "# # # #  start rebuilding";
    rebuildCollHandler->indexTaskService_->index(documentManager);
    CollectionPath& rebuildCollPath = rebuildCollHandler->indexTaskService_->getCollectionPath();
    rebuildCollDir = rebuildCollPath.getCollectionDataPath() + rebuildCollPath.getCurrCollectionDir();
    rebuildCollBaseDir = rebuildCollPath.getBasePath();
    } // lock scope

    // replace collection data with rebuilded data
    LOG(INFO) << "## stopCollection: " << collectionName_;
    CollectionManager::get()->stopCollection(collectionName_);
    LOG(INFO) << "## stopCollection: " << rebuildCollectionName_;
    CollectionManager::get()->stopCollection(rebuildCollectionName_);

    LOG(INFO) << "## update collection data for " << collectionName_;
    try
    {
        bfs::remove_all(collDir+"-backup");
        bfs::rename(collDir, collDir+"-backup");
        try {
            //bfs3::copy_directory(rebuildCollDir, collDir);
            bfs::rename(rebuildCollDir, collDir);
        }
        catch (const std::exception& e) {
            LOG(ERROR) << "failed to move data, rollback";
            bfs::rename(collDir+"-backup", collDir);
        }

        bfs::remove(collDir+"/scdlogs");
        bfs::copy_file(collDir+"-backup/scdlogs", collDir+"/scdlogs");
        bfs::remove_all(rebuildCollBaseDir);
    }
    catch (const std::exception& e)
    {
        LOG(ERROR) << e.what();
    }

    LOG(INFO) << "## re-startCollection: " << collectionName_;
    CollectionManager::get()->startCollection(collectionName_, configFile);

    LOG(INFO) << "## end RebuildTask for " << collectionName_;
    isRunning_ = false;
}

}