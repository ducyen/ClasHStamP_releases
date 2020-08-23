/* File generated by Đức's ClasHStamP */
#define __Context_INTERNAL__
#include "CommonInclude.h"
#include "Context.h"
#include "CalledDependency.h"                                   
/** @public @memberof Context */
static void Context_virtualFunc(
    Context* pContext,
    int param0
){
} /* Context_virtualFunc */

void Context_staticFunc(

){
} /* Context_staticFunc */

/** @public @memberof Context */
void Context_leafFunc(
    Context* pContext
){
} /* Context_leafFunc */

/** @public @memberof Context */
void Context_operation1(
    Context* pContext
){
} /* Context_operation1 */

/** @public @memberof Context */
void Context_operation2(
    Context* pContext
){
} /* Context_operation2 */

BaseClass* Context_Copy( Context* pContext, const Context* pSource ){
    BaseClass_Copy( ( BaseClass* )pContext, ( BaseClass* )pSource );
    pContext->attribute1 = pSource->attribute1;
    pContext->attribute0 = pSource->attribute0;
    pContext->anAggregation = pSource->anAggregation;
    memcpy( &pContext->aComposition, &pSource->aComposition, sizeof( pContext->aComposition ) );
    return ( BaseClass* )pContext;
}
const BaseClassVtbl gContextVtbl = {
    .pvirtualFunc                = Context_virtualFunc,
};
