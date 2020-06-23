#define __MAIN_INTERNAL__
#include <stdio.h>

int InputValue(char* pMsg);

#include "CommonInclude.h"
#include "Model/ContextImpl.h"

int InputValue(char* pMsg) {
    char n;
    printf( pMsg );
    scanf_s( "%c", &n );
    char c = 0;
    while( c != '\n' ){
        scanf_s( "%c", &c );
    }
    return n - '0';
}

int main( void ){
    CONTEXT_IMPL ctxTest = ContextImpl_Init( Composition_Init( 3 ) );
    char n;
    do {
        ContextImpl_Start( &ctxTest );
        do {
            n = InputValue( "Enter event number('q': quit, 'r':restart): E" );
            ContextImpl_EventProc( &ctxTest, (CONTEXT_IMPL_EVENT)n, NULL);
        } while (n+'0' != 'q' && n+'0' != 'r');
    }while (n+'0' != 'q');

}

