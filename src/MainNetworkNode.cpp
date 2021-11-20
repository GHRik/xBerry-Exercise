#include "MainNetworkNode.hpp"


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
    this->t1 = std::thread(&MainNetworkNode::routine,this);
    return code;
}

ErrorCodes MainNetworkNode::routine()
{
    ErrorCodes code = ErrorCodes::NOT_OK;
    logger->logInfo("Start routine in main network object");
    while (this->actual_status == Status::PROCESSING)
    {
        std::chrono::milliseconds timespan(3000);
        std::this_thread::sleep_for(timespan);
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
    buffor.insert(buffor.begin()+actualSizeBuffor,value);
    ++actualSizeBuffor;

    conditional_var = false;
    return ErrorCodes::OK;
}

void MainNetworkNode::stop()
{
    actual_status = Status::STOP;
    t1.join();
}
