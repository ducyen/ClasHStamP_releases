#pragma once
/* File generated by Đức's ClasHStamP */
#include "Generic/CommonInclude.h"
#include "Abstracts/CondimentDecorator.hpp"                     

class Soy: public CondimentDecorator{
    public: virtual double cost(
    ){
        return .15 + beverage->cost();
    } /* Soy.cost */
    protected: virtual String getDescription() const {
        return (String)beverage->m_description + ", Soy";
    };
    friend class Main;
    public:  Soy(
        Beverage *_beverage
    ):  CondimentDecorator( _beverage )
    {
    }                                                                                           
};
