#ifndef MAINNETWORKNODE_HPP
#define MAINNETWORKNODE_HPP

#include "iLifeCycle.hpp"
#include "iLogger.hpp"

class MainNetworkNode : public iLifeCycle
{
    public:
        MainNetworkNode(size_t bufforSize, iLifeCycle *lifeCycle, iLogger *logger);
        virtual ~MainNetworkNode();
        ErrorCodes registry(iLifeCycle *ptrToRegistry);
        ErrorCodes run(){return ErrorCodes::NOT_OK;}
    private:
        size_t bufforSize;
        iLifeCycle *lifeCycle;
        iLogger *logger;


};

#endif // MAINNETWORKNODE_HPP
