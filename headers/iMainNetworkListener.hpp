#ifndef IMAINNETWORKLISTENER_HPP
#define IMAINNETWORKLISTENER_HPP


#include "utils.hpp"

class iMainNetworkListener
{
    public:
        iMainNetworkListener();
        virtual ~iMainNetworkListener();
        virtual ErrorCodes readBuffor() = 0;
        virtual ErrorCodes writeToBuffor(int value) = 0;
};

#endif // IMAINNETWORKLISTENER_HPP
