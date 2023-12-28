/* File generated by Đức's ClasHStamP */
package model;

import java.io.*;
import java.util.*;
import model.Context;
import base.*;

public  class AnyStatePtn extends Context
{
    public enum _EventId {
        ev0,
        ev1,
        ev2,
        ev3,
        Num
    };
    static class AnyStateStm extends Statemachine {
        public static class AnyStateTop extends TopState {
            private static TopState singleInstance = new AnyStateTop();
            public static TopState GetInstance() { return singleInstance; }
        }
        public static class InitPt1 extends Pseudostate {
            private static Pseudostate singleInstance = new InitPt1();
            public static Pseudostate GetInstance() { return singleInstance; }
        }
        public static class InitPt2 extends Pseudostate {
            private static Pseudostate singleInstance = new InitPt2();
            public static Pseudostate GetInstance() { return singleInstance; }
        }
        public static class CompositeState extends AnyStateTop {
            private static TopState singleInstance = new CompositeState();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    System.out.println(GetInstance().getClass() + "entry");
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                switch( _EventId.values()[nEventId] ){
                case ev0:{
                    pStm.BgnTrans( pContext, State0.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } break;
                case ev1:{
                    pStm.m_bIsExternTrans = true;
                    pStm.BgnTrans( pContext, State1.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } break;
                case ev2:{
                    pStm.m_bIsExternTrans = true;
                    pStm.BgnTrans( pContext, State2.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } break;
                case ev3:{
                    pStm.BgnTrans( pContext, State3.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } break;
                default: break;
                }
                return bResult;
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    System.out.println(GetInstance().getClass() + "exit");
                }
            }
        };
        public static class State0 extends CompositeState {
            private static TopState singleInstance = new State0();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    super.Entry( pContext, pStm );
                    System.out.println(GetInstance().getClass() + "entry");
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                return bResult ? bResult : super.EventProc( pContext, pStm, nEventId, pParams );
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    System.out.println(GetInstance().getClass() + "exit");
                    super.Exit(pContext, pStm);
                }
            }
        };
        public static class State1 extends CompositeState {
            private static TopState singleInstance = new State1();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    super.Entry( pContext, pStm );
                    System.out.println(GetInstance().getClass() + "entry");
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                return bResult ? bResult : super.EventProc( pContext, pStm, nEventId, pParams );
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    System.out.println(GetInstance().getClass() + "exit");
                    super.Exit(pContext, pStm);
                }
            }
        };
        public static class State2 extends CompositeState {
            private static TopState singleInstance = new State2();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    super.Entry( pContext, pStm );
                    System.out.println(GetInstance().getClass() + "entry");
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                return bResult ? bResult : super.EventProc( pContext, pStm, nEventId, pParams );
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    System.out.println(GetInstance().getClass() + "exit");
                    super.Exit(pContext, pStm);
                }
            }
        };
        public static class State3 extends CompositeState {
            private static TopState singleInstance = new State3();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    super.Entry( pContext, pStm );
                    System.out.println(GetInstance().getClass() + "entry");
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                return bResult ? bResult : super.EventProc( pContext, pStm, nEventId, pParams );
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    System.out.println(GetInstance().getClass() + "exit");
                    super.Exit(pContext, pStm);
                }
            }
        };
        public boolean DefaultTrans( Context pContext ){
            boolean bResult = false;
            Statemachine pStm = this;
            do {
                if (m_pCurrentState == AnyStateTop.GetInstance() && m_pPseudostate == AnyStateStm.InitPt1.GetInstance()) {
                    pStm.BgnTrans( pContext, CompositeState.GetInstance(), InitPt2.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState == CompositeState.GetInstance() && m_pPseudostate == AnyStateStm.InitPt2.GetInstance()) {
                    pStm.BgnTrans( pContext, State0.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState != m_pPseudostate && m_pPseudostate instanceof AnyStateTop) {
                    pStm.BgnTrans( pContext, (TopState)m_pPseudostate );
                    pStm.EndTrans( pContext );
                } else {
                }
            } while (false);
            return bResult;
        }
        public boolean Reset(Context pContext, Statemachine pParentStm, Pseudostate pEntryPoint) {
            m_pParentStm = pParentStm;
            if (pEntryPoint == null) {
                if (IsFinished()) {
                    m_pPseudostate = InitPt1.GetInstance();
                }
            } else {
                if (IsFinished()) {
                    m_pPseudostate = pEntryPoint;
                    return false;
                } else {
                    m_pPseudostate = pEntryPoint;
                }                    
            }
            return RunToCompletion(pContext);
        }
        public boolean EventProc(Context pContext, int nEventId, EventParams pParams){
            boolean bResult = false;
            m_pLCAState = TopState.GetInstance();
            bResult = m_pCurrentState.EventProc(pContext, this, nEventId, pParams);
            RunToCompletion(pContext);
            return bResult;
        }
        public boolean IsIn(TopState pCompositeState) {
            if (super.IsIn(pCompositeState)) { return true; }
            return false;
        }
        public boolean Abort(Context pContext) {
            m_pSourceState = AnyStateTop.GetInstance();
            BgnTrans(pContext, AnyStateTop.GetInstance());
            EndTrans(pContext);
            return true;
        }
        public boolean IsFinished() {
            return m_pCurrentState == AnyStateTop.GetInstance() && m_pCurrentState == m_pPseudostate;
        }
        public AnyStateStm(){ super(AnyStateTop.GetInstance(), AnyStateTop.GetInstance()); }
    };
    public  AnyStatePtn(
        int _attribute0
    ) {
        super( _attribute0 );

    }                                                                                           
    AnyStateStm mainStm = new AnyStateStm();                    
    public boolean Start() {
            mainStm.Abort(this);
        return mainStm.Reset(this, null, null);
    }
    public boolean EventProc(int nEventId, EventParams pParams) {
        return mainStm.EventProc(this, nEventId, pParams);
    }
    public boolean IsIn(TopState pState) {
        return mainStm.IsIn(pState);
    }
}