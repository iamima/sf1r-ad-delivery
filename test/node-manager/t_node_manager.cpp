#include <boost/test/unit_test.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/filesystem.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>

#include <iostream>

#include <node-manager/DistributedSynchroFactory.h>

using namespace std;
using namespace sf1r;
using namespace boost;
using namespace boost::lambda;

void callback_on_consumed(bool isSuccess)
{
    cout <<"--> callback on consume finished: "<<isSuccess<<endl;
}

bool callback_on_produced(const std::string& datapath)
{
    cout<<"--> callback on produced: "<<datapath<<endl;

    cout<<"Consuming ..." <<endl;
    sleep(5);

    return true;
}

void thread_consumer_run()
{
    SynchroConsumerPtr scp =
            DistributedSynchroFactory::makeConsumer(DistributedSynchroFactory::SYNCHRO_TYPE_PRODUCT_MANAGER);

    scp->watchProducer(callback_on_produced, true);
}

BOOST_AUTO_TEST_SUITE( t_zookeeper )

BOOST_AUTO_TEST_CASE( node_manager_synchro )
{
    // set default config
    DistributedTopologyConfig dsTopologyConfig;
    dsTopologyConfig.clusterId_ = "zhongxia";
    dsTopologyConfig.nodeNum_ = 2;
    dsTopologyConfig.curSF1Node_.host_ = "172.16.0.36";
    dsTopologyConfig.curSF1Node_.nodeId_ = 1;
    dsTopologyConfig.curSF1Node_.replicaId_ = 1;
    DistributedUtilConfig dsUtilConfig;
    dsUtilConfig.zkConfig_.zkHosts_ = "172.16.0.161:2181,172.16.0.162:2181,172.16.0.163:2181";
    dsUtilConfig.zkConfig_.zkRecvTimeout_ = 2000;

    NodeManagerSingleton::get()->initWithConfig(dsTopologyConfig, dsUtilConfig);

    // Consumer
    boost::thread consumer_thread(thread_consumer_run);

    // Producer
    {
    SynchroProducerPtr spd =
        DistributedSynchroFactory::makeProcuder(DistributedSynchroFactory::SYNCHRO_TYPE_PRODUCT_MANAGER);
    spd->produce("/data/scd", callback_on_consumed);
    bool ret;
    spd->waitConsumers(ret);
    cout << "Producer: wait consumers ended " <<ret<<endl;

    spd->produce("/data/scd2", callback_on_consumed);

    while (true)
        sleep(1);
    }
}

BOOST_AUTO_TEST_SUITE_END()
