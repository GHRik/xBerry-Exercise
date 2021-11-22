#include "MainNetworkNode.hpp"


MainNetworkNode::MainNetworkNode(size_t bufforSize, iLifeCycle *lifeCycle, iLogger *logger)
: bufforSize(bufforSize), lifeCycle(lifeCycle), logger(logger), conditional_var(false)
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
        std::chrono::milliseconds timespan(2000);
        std::this_thread::sleep_for(timespan);
        code = readBuffor();
    }

    return code;
}

ErrorCodes MainNetworkNode::readBuffor()
{
    ErrorCodes code = ErrorCodes::NOT_OK;
    for(size_t i = 0; i < buffor.size(); ++i )
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
    while(conditional_var)
    {
        std::chrono::milliseconds timespan(1);
        std::this_thread::sleep_for(timespan);
        if(actual_status == Status::STOP)
        {
            return ErrorCodes::OK;
        }
    }
    conditional_var = true;
    if(actualSizeBuffor >= bufforSize-1)
    {
        actualSizeBuffor = 0;
    }
    buffor[actualSizeBuffor] = value;
    ++actualSizeBuffor;

    conditional_var = false;
    return ErrorCodes::OK;
}

void MainNetworkNode::stop()
{
    actual_status = Status::STOP;
    conditional_var = false;
    t1.join();
}
