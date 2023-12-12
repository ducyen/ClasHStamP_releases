/* File generated by Đức's ClasHStamP */
#define __ContextImpl_INTERNAL__
#include "CommonInclude.h"
#include "ContextImpl.h"
/* AnEnum列挙型の値から文字列に変換する関数（デバッグ用） */
const TCHAR* AnEnum_toString( AnEnum value ){
    switch( value ){
    case One: return _T( "One" );
    case Two: return _T( "Two" );
    case Three: return _T( "Three" );
    default: return _T( "AnEnum_UNKNOWN" );
    }
}
const TCHAR* ContextImplEvent_toString( ContextImpl_EVENT value ){
    switch( value ){
    case ContextImpl_E1: return _T( "E1" );
    case ContextImpl_E2: return _T( "E2" );
    case ContextImpl_E3: return _T( "E3" );
    default: return _T( "ContextImpl_UNKNOWN" );
    }
}
BOOL ContextImpl_EventProc( ContextImpl* pContextImpl, ContextImpl_EVENT nEventId, void* pEventParams ){
    return MainStm_EventProc( pContextImpl, &pContextImpl->mainStm, nEventId, pEventParams );
}
BOOL ContextImpl_Start( ContextImpl* pContextImpl ){
    MainStm_Abort( pContextImpl, &pContextImpl->mainStm );
    return MainStm_Reset( pContextImpl, &pContextImpl->mainStm, NULL, STATE_UNDEF );
}
BOOL ContextImpl_IsIn( ContextImpl* pContextImpl, UINT32 nState ){
    return MainStm_IsIn( &pContextImpl->mainStm, nState );
}
/** @protected @memberof ContextImpl */
static void ContextImpl_protectedMethod(
    ContextImpl* pContextImpl
){
} /* ContextImpl_protectedMethod */

boolean ContextImpl_checkE1Params(
    EventParams* e
){
    return ( ( E1Params* )e )->x == Two;
    #define checkE1Params ContextImpl_checkE1Params             // Just for demonstration
} /* ContextImpl_checkE1Params */

static void SecondaryRoad_BgnTrans( ContextImpl *pSecondaryRoadTop, SecondaryRoad* pStm, UINT32 targetState, UINT32 initState );
static void SecondaryRoad_EndTrans( ContextImpl *pSecondaryRoadTop, SecondaryRoad* pStm );
static BOOL SecondaryRoad_Reset( ContextImpl* pSecondaryRoadTop, SecondaryRoad* pStm, HdStateMachine* pParentStm, UINT32 nEntryPoint );
static BOOL SecondaryRoad_Abort( ContextImpl* pSecondaryRoadTop, SecondaryRoad* pStm );
static BOOL SecondaryRoad_EventProc( ContextImpl* pSecondaryRoadTop, SecondaryRoad* pStm, ContextImpl_EVENT nEventId, void* pEventParams );
static BOOL SecondaryRoad_RunToCompletion( ContextImpl* pSecondaryRoadTop, SecondaryRoad* pStm );
static void SecondaryRoad_SRed_Entry( ContextImpl* pContextImpl, SecondaryRoad* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, SecondaryRoad_SRed ) ){
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL SecondaryRoad_SRed_EventProc( ContextImpl* pContextImpl, SecondaryRoad* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = SecondaryRoad_SRed;
    return bResult;
}
static void SecondaryRoad_SRed_Exit( ContextImpl* pContextImpl, SecondaryRoad* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, SecondaryRoad_SRed ) ){ 
        printf( "%s\n", __FUNCTION__ );
    }
}
static void SecondaryRoad_SYellow_Entry( ContextImpl* pContextImpl, SecondaryRoad* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, SecondaryRoad_SYellow ) ){
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL SecondaryRoad_SYellow_EventProc( ContextImpl* pContextImpl, SecondaryRoad* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = SecondaryRoad_SYellow;
    switch( nEventId ){
    case ContextImpl_E2:{
        SecondaryRoad_BgnTrans( pContextImpl, pStm, SecondaryRoad_PRedWait, STATE_UNDEF );
        SecondaryRoad_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult;
}
static void SecondaryRoad_SYellow_Exit( ContextImpl* pContextImpl, SecondaryRoad* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, SecondaryRoad_SYellow ) ){ 
        printf( "%s\n", __FUNCTION__ );
    }
}
static void SecondaryRoad_SGreen_Entry( ContextImpl* pContextImpl, SecondaryRoad* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, SecondaryRoad_SGreen ) ){
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL SecondaryRoad_SGreen_EventProc( ContextImpl* pContextImpl, SecondaryRoad* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = SecondaryRoad_SGreen;
    switch( nEventId ){
    case ContextImpl_E2:{
        SecondaryRoad_BgnTrans( pContextImpl, pStm, SecondaryRoad_SYellow, STATE_UNDEF );
        SecondaryRoad_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult;
}
static void SecondaryRoad_SGreen_Exit( ContextImpl* pContextImpl, SecondaryRoad* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, SecondaryRoad_SGreen ) ){ 
        printf( "%s\n", __FUNCTION__ );
    }
}
static void SecondaryRoad_PRedWait_Entry( ContextImpl* pContextImpl, SecondaryRoad* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, SecondaryRoad_PRedWait ) ){
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL SecondaryRoad_PRedWait_EventProc( ContextImpl* pContextImpl, SecondaryRoad* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = SecondaryRoad_PRedWait;
    return bResult;
}
static void SecondaryRoad_PRedWait_Exit( ContextImpl* pContextImpl, SecondaryRoad* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, SecondaryRoad_PRedWait ) ){ 
        printf( "%s\n", __FUNCTION__ );
    }
}
static void SecondaryRoad_EndTrans( ContextImpl *pContextImpl, SecondaryRoad* pStm ){
    pStm->base.nCurrentState = pStm->base.nTargetState;
    pStm->base.bIsExternTrans = FALSE;
    switch( pStm->base.nCurrentState ){
    case SecondaryRoad_SRed:    SecondaryRoad_SRed_Entry( pContextImpl, pStm ); break;
    case SecondaryRoad_SYellow: SecondaryRoad_SYellow_Entry( pContextImpl, pStm ); break;
    case SecondaryRoad_SGreen:  SecondaryRoad_SGreen_Entry( pContextImpl, pStm ); break;
    case SecondaryRoad_PRedWait:SecondaryRoad_PRedWait_Entry( pContextImpl, pStm ); break;
    default: break;
    }
}
static void SecondaryRoad_BgnTrans( ContextImpl *pContextImpl, SecondaryRoad* pStm, UINT32 targetState, UINT32 initState ){
    pStm->base.nTargetState = targetState;
    pStm->base.nPseudostate = targetState;
    if( initState ){
        pStm->base.nPseudostate = initState;
    }
    switch( pStm->base.nCurrentState ){
    case SecondaryRoad_SRed:    SecondaryRoad_SRed_Exit( pContextImpl, pStm ); break;
    case SecondaryRoad_SYellow: SecondaryRoad_SYellow_Exit( pContextImpl, pStm ); break;
    case SecondaryRoad_SGreen:  SecondaryRoad_SGreen_Exit( pContextImpl, pStm ); break;
    case SecondaryRoad_PRedWait:SecondaryRoad_PRedWait_Exit( pContextImpl, pStm ); break;
    default: break;
    }
}
static BOOL SecondaryRoad_StateDefaultTrans( ContextImpl* pContextImpl, SecondaryRoad* pStm ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = pStm->base.nCurrentState;
    pStm->base.nLCAState = STATE_UNDEF;
    do{   if( pStm->base.nCurrentState == SecondaryRoad_SecondaryRoadTop && pStm->base.nPseudostate == SecondaryRoad_InitialPseudostate2 ){
        SecondaryRoad_BgnTrans( pContextImpl, pStm, SecondaryRoad_SGreen, STATE_UNDEF );
        SecondaryRoad_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    }else if( pStm->base.nCurrentState != pStm->base.nPseudostate && IS_IN(pStm->base.nPseudostate, SecondaryRoad_SecondaryRoadTop) ){
        SecondaryRoad_BgnTrans( pContextImpl, pStm, pStm->base.nPseudostate, STATE_UNDEF );
        SecondaryRoad_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    }else{
    }   }while( FALSE );
    return bResult;
}
static BOOL SecondaryRoad_RunToCompletion( ContextImpl* pContextImpl, SecondaryRoad* pStm ){
    BOOL bResult;
    do{
        bResult = SecondaryRoad_StateDefaultTrans( pContextImpl, pStm );
    } while ( bResult );
    return bResult;
}
static BOOL SecondaryRoad_Reset( ContextImpl* pContextImpl, SecondaryRoad* pStm, HdStateMachine* pParentStm, UINT32 nEntryPoint ) {
    pStm->base.pParentStm = pParentStm;
    if( nEntryPoint == NULL ){
        if( SecondaryRoad_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = SecondaryRoad_InitialPseudostate2;
        }
    }else{
        if( SecondaryRoad_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = nEntryPoint;
            return FALSE;
        }else{
            pStm->base.nPseudostate = nEntryPoint;
        }
    }
    if( nEntryPoint != STATE_UNDEF && nEntryPoint <= STATE_TOP ){
    }
    return SecondaryRoad_RunToCompletion( pContextImpl, pStm );
}
static BOOL SecondaryRoad_EventProc( ContextImpl* pContextImpl, SecondaryRoad* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nLCAState = STATE_UNDEF;
    switch( pStm->base.nCurrentState ){
    case SecondaryRoad_SRed:                    bResult |= SecondaryRoad_SRed_EventProc( pContextImpl, pStm, nEventId, pEventParams ); break;
    case SecondaryRoad_SYellow:                 bResult |= SecondaryRoad_SYellow_EventProc( pContextImpl, pStm, nEventId, pEventParams ); break;
    case SecondaryRoad_SGreen:                  bResult |= SecondaryRoad_SGreen_EventProc( pContextImpl, pStm, nEventId, pEventParams ); break;
    case SecondaryRoad_PRedWait:                bResult |= SecondaryRoad_PRedWait_EventProc( pContextImpl, pStm, nEventId, pEventParams ); break;
    default: break;
    }
    SecondaryRoad_RunToCompletion( pContextImpl, pStm );
    return bResult;
}
static BOOL SecondaryRoad_IsIn( SecondaryRoad* pStm, UINT32 nCompositeState ) {
    if( IS_IN( pStm->base.nCurrentState, nCompositeState ) ){ return TRUE; }
    return FALSE;
}
static BOOL SecondaryRoad_Abort( ContextImpl* pContextImpl, SecondaryRoad* pStm ) {
    pStm->base.nSourceState = SecondaryRoad_SecondaryRoadTop;
    SecondaryRoad_BgnTrans( pContextImpl, pStm, SecondaryRoad_SecondaryRoadTop, STATE_UNDEF );
    SecondaryRoad_EndTrans( pContextImpl, pStm );
    return TRUE;
}
int SecondaryRoad_IsFinished(SecondaryRoad* pSecondaryRoad){
    return pSecondaryRoad->base.nCurrentState == SecondaryRoad_SecondaryRoadTop && pSecondaryRoad->base.nCurrentState == pSecondaryRoad->base.nPseudostate;
}
static void MainStm_BgnTrans( ContextImpl *pMainTop, MainStm* pStm, UINT32 targetState, UINT32 initState );
static void MainStm_EndTrans( ContextImpl *pMainTop, MainStm* pStm );
static BOOL MainStm_Reset( ContextImpl* pMainTop, MainStm* pStm, HdStateMachine* pParentStm, UINT32 nEntryPoint );
static BOOL MainStm_Abort( ContextImpl* pMainTop, MainStm* pStm );
static BOOL MainStm_EventProc( ContextImpl* pMainTop, MainStm* pStm, ContextImpl_EVENT nEventId, void* pEventParams );
static BOOL MainStm_RunToCompletion( ContextImpl* pMainTop, MainStm* pStm );
static void MainStm_Starting_Entry( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, MainStm_Starting ) ){
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL MainStm_Starting_EventProc( ContextImpl* pContextImpl, MainStm* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = MainStm_Starting;
    switch( nEventId ){
    case ContextImpl_E1:{
        E1Params* e = ( E1Params* )pEventParams;
        MainStm_BgnTrans( pContextImpl, pStm, MainStm_ManagingThroughTraffic, MainStm_InitialPseudostate1 );
        MainStm_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult;
}
static void MainStm_Starting_Exit( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, MainStm_Starting ) ){ 
        printf( "%s\n", __FUNCTION__ );
    }
}
static void MainStm_ManagingThroughTraffic_Entry( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, MainStm_ManagingThroughTraffic ) ){
        printf( "%s\n", __FUNCTION__ );
        SecondaryRoad_Reset( pContextImpl, &pStm->SubmachineState0SecondaryRoad, &pStm->base, STATE_UNDEF );
    }
}
static BOOL MainStm_ManagingThroughTraffic_EventProc( ContextImpl* pContextImpl, MainStm* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = MainStm_ManagingThroughTraffic;
    return bResult;
}
static void MainStm_ManagingThroughTraffic_Exit( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, MainStm_ManagingThroughTraffic ) ){ 
        SecondaryRoad_Abort( pContextImpl, &pStm->SubmachineState0SecondaryRoad );
        printf( "%s\n", __FUNCTION__ );
    }
}
static void MainStm_PRed_Entry( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, MainStm_PRed ) ){
        MainStm_ManagingThroughTraffic_Entry( pContextImpl, pStm );
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL MainStm_PRed_EventProc( ContextImpl* pContextImpl, MainStm* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = MainStm_PRed;
    switch( nEventId ){
    case ContextImpl_E3:{
        if (ContextImpl_IsIn( pContextImpl, SecondaryRoad_PRedWait )) {
            MainStm_BgnTrans( pContextImpl, pStm, MainStm_PGreen, STATE_UNDEF );
            SecondaryRoad_Reset( pContextImpl, &pStm->SubmachineState0SecondaryRoad, &pStm->base, SecondaryRoad_SRed );
            MainStm_EndTrans( pContextImpl, pStm );
            bResult = TRUE;
        }
    } break;
    default: break;
    }
    return bResult ? bResult : MainStm_ManagingThroughTraffic_EventProc( pContextImpl, pStm, nEventId, pEventParams );
}
static void MainStm_PRed_Exit( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, MainStm_PRed ) ){ 
        printf( "%s\n", __FUNCTION__ );
        MainStm_ManagingThroughTraffic_Exit( pContextImpl, pStm );
    }
}
static void MainStm_PGreen_Entry( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, MainStm_PGreen ) ){
        MainStm_ManagingThroughTraffic_Entry( pContextImpl, pStm );
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL MainStm_PGreen_EventProc( ContextImpl* pContextImpl, MainStm* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = MainStm_PGreen;
    switch( nEventId ){
    case ContextImpl_E2:{
        MainStm_BgnTrans( pContextImpl, pStm, MainStm_PYellow, STATE_UNDEF );
        MainStm_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult ? bResult : MainStm_ManagingThroughTraffic_EventProc( pContextImpl, pStm, nEventId, pEventParams );
}
static void MainStm_PGreen_Exit( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, MainStm_PGreen ) ){ 
        printf( "%s\n", __FUNCTION__ );
        MainStm_ManagingThroughTraffic_Exit( pContextImpl, pStm );
    }
}
static void MainStm_PYellow_Entry( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, MainStm_PYellow ) ){
        MainStm_ManagingThroughTraffic_Entry( pContextImpl, pStm );
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL MainStm_PYellow_EventProc( ContextImpl* pContextImpl, MainStm* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = MainStm_PYellow;
    switch( nEventId ){
    case ContextImpl_E2:{
        MainStm_BgnTrans( pContextImpl, pStm, MainStm_SRedWait, STATE_UNDEF );
        MainStm_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult ? bResult : MainStm_ManagingThroughTraffic_EventProc( pContextImpl, pStm, nEventId, pEventParams );
}
static void MainStm_PYellow_Exit( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, MainStm_PYellow ) ){ 
        printf( "%s\n", __FUNCTION__ );
        MainStm_ManagingThroughTraffic_Exit( pContextImpl, pStm );
    }
}
static void MainStm_SRedWait_Entry( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, MainStm_SRedWait ) ){
        MainStm_ManagingThroughTraffic_Entry( pContextImpl, pStm );
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL MainStm_SRedWait_EventProc( ContextImpl* pContextImpl, MainStm* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = MainStm_SRedWait;
    switch( nEventId ){
    case ContextImpl_E3:{
        if (ContextImpl_IsIn( pContextImpl, SecondaryRoad_SRed )) {
            MainStm_BgnTrans( pContextImpl, pStm, MainStm_PRed, STATE_UNDEF );
            SecondaryRoad_Reset( pContextImpl, &pStm->SubmachineState0SecondaryRoad, &pStm->base, SecondaryRoad_SGreen );
            MainStm_EndTrans( pContextImpl, pStm );
            bResult = TRUE;
        }
    } break;
    default: break;
    }
    return bResult ? bResult : MainStm_ManagingThroughTraffic_EventProc( pContextImpl, pStm, nEventId, pEventParams );
}
static void MainStm_SRedWait_Exit( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, MainStm_SRedWait ) ){ 
        printf( "%s\n", __FUNCTION__ );
        MainStm_ManagingThroughTraffic_Exit( pContextImpl, pStm );
    }
}
static void MainStm_EndTrans( ContextImpl *pContextImpl, MainStm* pStm ){
    pStm->base.nCurrentState = pStm->base.nTargetState;
    pStm->base.bIsExternTrans = FALSE;
    switch( pStm->base.nCurrentState ){
    case MainStm_Starting:      MainStm_Starting_Entry( pContextImpl, pStm ); break;
    case MainStm_ManagingThroughTraffic:MainStm_ManagingThroughTraffic_Entry( pContextImpl, pStm ); break;
    case MainStm_PRed:          MainStm_PRed_Entry( pContextImpl, pStm ); break;
    case MainStm_PGreen:        MainStm_PGreen_Entry( pContextImpl, pStm ); break;
    case MainStm_PYellow:       MainStm_PYellow_Entry( pContextImpl, pStm ); break;
    case MainStm_SRedWait:      MainStm_SRedWait_Entry( pContextImpl, pStm ); break;
    default: break;
    }
}
static void MainStm_BgnTrans( ContextImpl *pContextImpl, MainStm* pStm, UINT32 targetState, UINT32 initState ){
    pStm->base.nTargetState = targetState;
    pStm->base.nPseudostate = targetState;
    if( initState ){
        pStm->base.nPseudostate = initState;
    }
    switch( pStm->base.nCurrentState ){
    case MainStm_Starting:      MainStm_Starting_Exit( pContextImpl, pStm ); break;
    case MainStm_ManagingThroughTraffic:MainStm_ManagingThroughTraffic_Exit( pContextImpl, pStm ); break;
    case MainStm_PRed:          MainStm_PRed_Exit( pContextImpl, pStm ); break;
    case MainStm_PGreen:        MainStm_PGreen_Exit( pContextImpl, pStm ); break;
    case MainStm_PYellow:       MainStm_PYellow_Exit( pContextImpl, pStm ); break;
    case MainStm_SRedWait:      MainStm_SRedWait_Exit( pContextImpl, pStm ); break;
    default: break;
    }
}
static BOOL MainStm_StateDefaultTrans( ContextImpl* pContextImpl, MainStm* pStm ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = pStm->base.nCurrentState;
    pStm->base.nLCAState = STATE_UNDEF;
    bResult |= SecondaryRoad_StateDefaultTrans( pContextImpl, &pStm->SubmachineState0SecondaryRoad );
    do{   if( pStm->base.nCurrentState == MainStm_MainTop && pStm->base.nPseudostate == MainStm_InitialPseudostate0 ){
        MainStm_BgnTrans( pContextImpl, pStm, MainStm_Starting, STATE_UNDEF );
        MainStm_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    }else if( pStm->base.nCurrentState == MainStm_ManagingThroughTraffic && pStm->base.nPseudostate == MainStm_InitialPseudostate1 ){
        MainStm_BgnTrans( pContextImpl, pStm, MainStm_PRed, STATE_UNDEF );
        MainStm_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    }else if( pStm->base.nCurrentState != pStm->base.nPseudostate && IS_IN(pStm->base.nPseudostate, MainStm_MainTop) ){
        MainStm_BgnTrans( pContextImpl, pStm, pStm->base.nPseudostate, STATE_UNDEF );
        MainStm_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    }else{
    }   }while( FALSE );
    return bResult;
}
static BOOL MainStm_RunToCompletion( ContextImpl* pContextImpl, MainStm* pStm ){
    BOOL bResult;
    do{
        bResult = MainStm_StateDefaultTrans( pContextImpl, pStm );
    } while ( bResult );
    return bResult;
}
static BOOL MainStm_Reset( ContextImpl* pContextImpl, MainStm* pStm, HdStateMachine* pParentStm, UINT32 nEntryPoint ) {
    pStm->base.pParentStm = pParentStm;
    if( nEntryPoint == NULL ){
        if( MainStm_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = MainStm_InitialPseudostate0;
        }
    }else{
        if( MainStm_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = nEntryPoint;
            return FALSE;
        }else{
            pStm->base.nPseudostate = nEntryPoint;
        }
    }
    if( nEntryPoint != STATE_UNDEF && nEntryPoint <= STATE_TOP ){
        SecondaryRoad_Reset( pContextImpl, &pStm->SubmachineState0SecondaryRoad, &pStm->base, nEntryPoint );
    }
    return MainStm_RunToCompletion( pContextImpl, pStm );
}
static BOOL MainStm_EventProc( ContextImpl* pContextImpl, MainStm* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nLCAState = STATE_UNDEF;
    bResult |= SecondaryRoad_EventProc( pContextImpl, &pStm->SubmachineState0SecondaryRoad, nEventId, pEventParams );
    switch( pStm->base.nCurrentState ){
    case MainStm_Starting:                      bResult |= MainStm_Starting_EventProc( pContextImpl, pStm, nEventId, pEventParams ); break;
    case MainStm_ManagingThroughTraffic:        bResult |= MainStm_ManagingThroughTraffic_EventProc( pContextImpl, pStm, nEventId, pEventParams ); break;
    case MainStm_PRed:                          bResult |= MainStm_PRed_EventProc( pContextImpl, pStm, nEventId, pEventParams ); break;
    case MainStm_PGreen:                        bResult |= MainStm_PGreen_EventProc( pContextImpl, pStm, nEventId, pEventParams ); break;
    case MainStm_PYellow:                       bResult |= MainStm_PYellow_EventProc( pContextImpl, pStm, nEventId, pEventParams ); break;
    case MainStm_SRedWait:                      bResult |= MainStm_SRedWait_EventProc( pContextImpl, pStm, nEventId, pEventParams ); break;
    default: break;
    }
    MainStm_RunToCompletion( pContextImpl, pStm );
    return bResult;
}
static BOOL MainStm_IsIn( MainStm* pStm, UINT32 nCompositeState ) {
    if( SecondaryRoad_IsIn( &pStm->SubmachineState0SecondaryRoad, nCompositeState ) ){ return TRUE; }
    if( IS_IN( pStm->base.nCurrentState, nCompositeState ) ){ return TRUE; }
    return FALSE;
}
static BOOL MainStm_Abort( ContextImpl* pContextImpl, MainStm* pStm ) {
    pStm->base.nSourceState = MainStm_MainTop;
    MainStm_BgnTrans( pContextImpl, pStm, MainStm_MainTop, STATE_UNDEF );
    MainStm_EndTrans( pContextImpl, pStm );
    return TRUE;
}
int MainStm_IsFinished(MainStm* pMainStm){
    return pMainStm->base.nCurrentState == MainStm_MainTop && pMainStm->base.nCurrentState == pMainStm->base.nPseudostate;
}
Context* ContextImpl_Copy( ContextImpl* pContextImpl, const ContextImpl* pSource ){
    Context_Copy( ( Context* )pContextImpl, ( Context* )pSource );
    return ( BaseClass* )pContextImpl;
}
const BaseClassVtbl gContextImplVtbl = {
    .pprotectedMethod            = ContextImpl_protectedMethod,
};