#ifndef LIFECYCLE_HPP
#define LIFECYCLE_HPP

#include "iLifeCycleMenager.hpp"
#include "iLifeCycle.hpp"
#include "Logger.hpp"


class LifeCycle : public iLifeCycleMenager, public iLifeCycle
{
    public:
        LifeCycle(iLogger *logger);
        virtual ~LifeCycle();
        void start();

        ErrorCodes registry(iLifeCycle *ptrToRegistry);
        ErrorCodes run(){return ErrorCodes::NOT_OK;}

    private:
        std::vector<iLifeCycle *> objectToLifeArray;
        iLogger *logger;

};

#endif // LIFECYCLE_HPP
