#ifndef LIFECYCLE_HPP
#define LIFECYCLE_HPP

#include "iLifeCycleMenager.hpp"
#include "Logger.hpp"

class LifeCycle : iLifeCycleMenager
{
    public:
        LifeCycle(Logger *logger) : logger(logger){};
        virtual ~LifeCycle();
        void run(){}

    private:
        std::vector<iLifeCycle *> objectToLifeArray;
        size_t amountOfObject;
        Logger *logger;

};

#endif // LIFECYCLE_HPP
