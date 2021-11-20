#ifndef ILIFECYCLE_HPP
#define ILIFECYCLE_HPP

#include "utils.hpp"

class iLifeCycle
{
    public:
        iLifeCycle();
        virtual ~iLifeCycle();
        virtual ErrorCodes registry(iLifeCycle *ptrToRegistry) = 0;
        virtual ErrorCodes run() = 0;
};

#endif // ILIFECYCLE_HPP
