#ifndef MAINNETWORKNODE_HPP
#define MAINNETWORKNODE_HPP

#include "iLifeCycle.hpp"
#include "iLogger.hpp"
#include "iMainNetworkListener.hpp"
#include <vector>

class MainNetworkNode : public iMainNetworkListener, public iLifeCycle
{
    public:
        MainNetworkNode(size_t bufforSize, iLifeCycle *lifeCycle, iLogger *logger);
        virtual ~MainNetworkNode();
        ErrorCodes registry(iLifeCycle *ptrToRegistry);
        ErrorCodes run();

        ErrorCodes readBuffor();
        ErrorCodes writeToBuffor(int value);
        std::vector<int> buffor;
        unsigned int actualSizeBuffor;
        size_t bufforSize;
    private:

        iLifeCycle *lifeCycle;
        iLogger *logger;




};

#endif // MAINNETWORKNODE_HPP
