#include <iostream>
#include <cassert>

int InputValue(char* pMsg);

#include "Statemachine.h"  /* @todo Duc */
#include "Context.hpp"
#include "ContextImpl.hpp"

int InputValue(char* pMsg) {
    char n;
    std::cout << pMsg;
    std::cin  >> n;
    return n - '0';
}

int main() {
    Composition aComp(4);
    ContextImpl ctxTest( aComp );
    int n;
    do {
        ctxTest.Start();
        do {
            n = InputValue( "Enter event number('q': quit, 'r':restart): E" );
            ctxTest.EventProc((EventId)n, nullptr);
        } while (n+'0' != 'q' && n+'0' != 'r');
    }while (n+'0' != 'q');

}
