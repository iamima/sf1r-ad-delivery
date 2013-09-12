#include "ProductScdReceiver.h"
#include <bundles/index/IndexTaskService.h>
#include <node-manager/MasterManagerBase.h>
#include <node-manager/NodeManagerBase.h>
#include <node-manager/DistributeFileSys.h>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

using namespace sf1r;
namespace bfs = boost::filesystem;
ProductScdReceiver::ProductScdReceiver(const std::string& syncID, const std::string& collectionName, const std::string& callback)
:index_service_(NULL)
,syncID_(syncID)
,collectionName_(collectionName)
,callback_type_(callback)
{
    syncConsumer_ = SynchroFactory::getConsumer(syncID);
    syncConsumer_->watchProducer(
            boost::bind(&ProductScdReceiver::Run, this, _1),
            collectionName);//in comment for increment data;

    syncConsumerRebuildComment_ = SynchroFactory::getConsumer(syncID + syncID_totalComment);
    syncConsumerRebuildComment_->watchProducer(
            boost::bind(&ProductScdReceiver::getTotalComment, this, _1),
            collectionName);//in comment for total data;
}

bool ProductScdReceiver::pushIndexRequest(const std::string& scd_source_dir)
{
    if (MasterManagerBase::get()->isDistributed())
    {
        if (NodeManagerBase::get()->isPrimary())
        {
            std::string json_req = "{\"collection\":\"" + collectionName_ + "\",\"index_scd_path\":\"" + scd_source_dir + "\",\"header\":{\"acl_tokens\":\"\",\"action\":\"index\",\"controller\":\"commands\"},\"uri\":\"commands/index\"}";
            if (callback_type_ == "rebuild")
            {
                json_req = "{\"collection\":\"" + collectionName_ + "\",\"index_scd_path\":\"" + scd_source_dir + "\",\"header\":{\"acl_tokens\":\"\",\"action\":\"rebuild_from_scd\",\"controller\":\"collection\"},\"uri\":\"collection/rebuild_from_scd\"}";
            }
            MasterManagerBase::get()->pushWriteReq(json_req);
            LOG(INFO) << "a json_req pushed from " << __FUNCTION__ << ", data:" << json_req;
        }
        else
        {
            LOG(INFO) << "ignore on replica node, " << __FUNCTION__;
        }
        return true;
    }
    else
        return index_service_->index(0, "", false);
}

bool ProductScdReceiver::onReceived(const std::string& scd_source_dir)
{
    return pushIndexRequest(scd_source_dir);// build index ....
}

bool ProductScdReceiver::getTotalComment(const std::string& scd_source_dir)
{
    std::string mine_source_dir = scd_source_dir;
    LOG(INFO)<<"ProductScdReceiver::getTotalComment "<<mine_source_dir<<std::endl;
    bool isRebuild = true;
    std::string rebuild_scd_dir = index_service_->getScdDir(isRebuild);
    LOG(INFO)<<"rebuild_scd_dir: " << rebuild_scd_dir;

    bfs::create_directories(rebuild_scd_dir);
    ScdParser parser(izenelib::util::UString::UTF_8);
    static const bfs::directory_iterator kItrEnd;
    std::vector<bfs::path> scd_list;
    if (!mine_source_dir.empty() && !DistributeFileSys::get()->isEnabled())
    {
        for (bfs::directory_iterator itr(mine_source_dir); itr != kItrEnd; ++itr)
        {
            if (bfs::is_regular_file(itr->status()))
            {
                std::string fileName = itr->path().filename().string();
                if (parser.checkSCDFormat(fileName) )
                {
                    LOG(INFO)<<"[ProductScdReceiver] find SCD "<<fileName<<std::endl;
                    scd_list.push_back(itr->path());
                }
            }
        }
        if(scd_list.empty())
        {
            LOG(INFO)<<"[ProductScdReceiver] No SCD file found."<<std::endl;
            return true;
        }
        bfs::path to_dir(rebuild_scd_dir);
        if(!CopyTotalCommentToDir_(scd_list, to_dir))
        {
            return false;
        }
    }
    return true;
}

bool ProductScdReceiver::Run(const std::string& scd_source_dir)
{
    LOG(INFO)<<"ProductScdReceiver::Run "<<scd_source_dir<<std::endl;
    if(index_service_==NULL)
    {
        return false;
    }
    std::string mine_source_dir = scd_source_dir;
    if (mine_source_dir.empty() && callback_type_ == "rebuild")
    {
        LOG(INFO) << "copying rebuild scd from index path.";
        mine_source_dir = index_service_->getScdDir(false);
    }
    if (!mine_source_dir.empty() && !DistributeFileSys::get()->isEnabled())
    {
        std::string index_scd_dir = index_service_->getScdDir(callback_type_ == "rebuild");
        bfs::create_directories(index_scd_dir);
        //copy scds in mine_source_dir/ to index_scd_dir/
        ScdParser parser(izenelib::util::UString::UTF_8);
        static const bfs::directory_iterator kItrEnd;
        std::vector<bfs::path> scd_list;
        for (bfs::directory_iterator itr(mine_source_dir); itr != kItrEnd; ++itr)
        {
            if (bfs::is_regular_file(itr->status()))
            {
                std::string fileName = itr->path().filename().string();
                if (parser.checkSCDFormat(fileName) )
                {
                    LOG(INFO)<<"[ProductScdReceiver] find SCD "<<fileName<<std::endl;
                    scd_list.push_back(itr->path());
                }
            }
        }
        if(scd_list.empty())
        {
            LOG(INFO)<<"[ProductScdReceiver] No SCD file found."<<std::endl;
            return true;
        }
        bfs::path to_dir(index_scd_dir);
        if(!CopyFileListToDir_(scd_list, to_dir))
        {
            return false;
        }
    }
    if (!DistributeFileSys::get()->isEnabled())
        mine_source_dir.clear();
    return pushIndexRequest(mine_source_dir);
}

bool ProductScdReceiver::CopyTotalCommentToDir_(const std::vector<boost::filesystem::path>& file_list, const boost::filesystem::path& to_dir)
{
    for(uint32_t i=0;i<file_list.size();i++)
    {
        std::string to_filename = file_list[i].filename().string();
        
        bfs::path to_file = to_dir/to_filename;
        try
        {
            if(!bfs::exists(to_file))
            {
                bfs::copy_file(file_list[i], to_file);
            }
            else
            {
                bfs::remove_all(to_file);
                bfs::copy_file(file_list[i], to_file);
            }
        }
        catch(std::exception& ex)
        {
            return false;
        }
    }
    return true;
}

bool ProductScdReceiver::CopyFileListToDir_(const std::vector<boost::filesystem::path>& file_list, const boost::filesystem::path& to_dir)
{
    std::vector<bfs::path> copied_file;
    for(uint32_t i=0;i<file_list.size();i++)
    {
        std::string to_filename = file_list[i].filename().string();
        bool failed = true;
        while(true)
        {
            bfs::path to_file = to_dir/to_filename;
            try
            {
                if(!bfs::exists(to_file))
                {
                    bfs::copy_file(file_list[i], to_file);
                    failed = false;
                }
            }
            catch(std::exception& ex)
            {

            }
            if(!failed)
            {
                break;
            }
            if(!NextScdFileName_(to_filename)) break;
        }
        if(failed) //rollback
        {
            for(uint32_t j=0;j<copied_file.size();j++)
            {
                bfs::remove_all(copied_file[j]);
            }
            return false;
        }
        else
        {
            bfs::path to_file = to_dir/to_filename;
            copied_file.push_back(to_file);
        }
    }
    return true;
}

bool ProductScdReceiver::NextScdFileName_(std::string& filename) const
{
    std::string scid = filename.substr(2,2);
    uint32_t cid = boost::lexical_cast<uint32_t>(scid);
    if(cid==99) return false;
    ++cid;
    std::string ofilename = filename;
    filename = ofilename.substr(0,2);
    boost::format formater("%02d");
    formater % cid;
    filename += formater.str();
    filename += ofilename.substr(4, ofilename.length()-4);
    return true;
}
