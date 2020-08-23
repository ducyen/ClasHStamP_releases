/* File generated by Đức's ClasHStamP */
#define __Mocha_INTERNAL__
#include "CommonInclude.h"
#include "Mocha.h"
/** @public @memberof Mocha */
static double Mocha_cost(
    Mocha* pMocha
){
    return .20 + Beverage_cost(pMocha->beverage);
} /* Mocha_cost */

String Mocha_GetDescription( const Mocha* pMocha ){
return MakeString( "This sample does not use this as polymorphism property. Instead, it uses constructor code to do it." );
}
CondimentDecorator* Mocha_Copy( Mocha* pMocha, const Mocha* pSource ){
    CondimentDecorator_Copy( ( CondimentDecorator* )pMocha, ( CondimentDecorator* )pSource );
    return ( Beverage* )pMocha;
}
const BeverageVtbl gMochaVtbl = {
    .pcost                       = Mocha_cost,
};
