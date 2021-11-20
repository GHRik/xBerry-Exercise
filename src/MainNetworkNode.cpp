#include "MainNetworkNode.hpp"

//#include<windows.h>

MainNetworkNode::MainNetworkNode(size_t bufforSize, iLifeCycle *lifeCycle, iLogger *logger)
: bufforSize(bufforSize), lifeCycle(lifeCycle), logger(logger)
{
    buffor.resize(bufforSize);
    actualSizeBuffor = 0;
    actual_status = Status::START;
}

MainNetworkNode::~MainNetworkNode()
{
    //dtor
}

ErrorCodes MainNetworkNode::registry(iLifeCycle *ptrToRegistry)
{
    return lifeCycle->registry(this);
}

ErrorCodes MainNetworkNode::run()
{
    ErrorCodes code = ErrorCodes::NOT_OK;
    actual_status = Status::PROCESSING;

    return code;
}

ErrorCodes MainNetworkNode::routine()
{
    ErrorCodes code = ErrorCodes::NOT_OK;
    while (actual_status == Status::PROCESSING)
    {
        //Sleep(3000);
        code = readBuffor();
    }
    return code;
}

ErrorCodes MainNetworkNode::readBuffor()
{
    ErrorCodes code = ErrorCodes::NOT_OK;
    for(size_t i = 0; i < actualSizeBuffor; ++i )
    {
        code = logger->logEvent("Sensors value: ",std::to_string(buffor[i]));
        if(code != ErrorCodes::OK)
        {
            return code;
        }
    }
    return code;
}

ErrorCodes MainNetworkNode::writeToBuffor(int value)
{
    bool conditional_var = false;
    while(conditional_var){};
    conditional_var = true;
    if(actualSizeBuffor >= bufforSize)
    {
        actualSizeBuffor = 0;
    }
    buffor.push_back(value);
    buffor.insert(buffor.begin()+actualSizeBuffor,value);
    ++actualSizeBuffor;

    conditional_var = false;
    return ErrorCodes::OK;
}
