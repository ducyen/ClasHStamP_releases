#pragma once
/* File generated by Đức's ClasHStamP */
#include "Generic/CommonInclude.h"
#include "Interfaces/ObserverIfc.hpp"                           

class Subject{
    public: virtual void registerObserver(
        ObserverIfc* o
    ) = 0;
    public: virtual void removeObserver(
        ObserverIfc* o
    ) = 0;
    public: virtual void notifyObserver(
    ) = 0;
    public:  Subject(
    )
    {
    }                                                                                           
};
