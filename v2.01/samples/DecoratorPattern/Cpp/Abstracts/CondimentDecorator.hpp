#pragma once
/* File generated by Đức's ClasHStamP */
#include "Generic/CommonInclude.h"
#include "Abstracts/Beverage.hpp"                               

class CondimentDecorator: public Beverage{
    public:  CondimentDecorator(
        Beverage *_beverage
    ):  Beverage( "Unknown Beverage" ),
        beverage( _beverage )
    {
    }                                                                                           
    protected: Beverage* beverage;                              
};
