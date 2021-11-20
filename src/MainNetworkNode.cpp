#include "MainNetworkNode.hpp"

MainNetworkNode::MainNetworkNode(size_t bufforSize, iLifeCycle *lifeCycle, iLogger *logger)
: bufforSize(bufforSize), lifeCycle(lifeCycle), logger(logger)
{
    //ctor
}

MainNetworkNode::~MainNetworkNode()
{
    //dtor
}

ErrorCodes MainNetworkNode::registry(iLifeCycle *ptrToRegistry)
{
    return lifeCycle->registry(this);
}
