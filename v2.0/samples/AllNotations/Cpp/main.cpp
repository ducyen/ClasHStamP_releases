#include <iostream>
#include <cassert>
#include <string>

int InputValue(char* pMsg);
void DisplayMsg(char* pMsg);

#include "Generic/Statemachine.h"  /* @todo Duc */
#include "Model/Context.hpp"
#include "Model/ContextImpl.hpp"

int InputValue(char* pMsg) {
    char n;
    std::cout << pMsg;
    std::cin  >> n;
    return n - '0';
}

void DisplayMsg(char* pMsg) {
    std::cout << pMsg << std::endl;
}

int main() {
    ContextImpl ctxTest( 4, "", 1, 2, 3, std::vector<Composition*>() );

    int n;
    do {
        ctxTest.Start();
        do {
            n = InputValue( "Enter event number('q': quit, 'r':restart): E" );
            ctxTest.EventProc((EventId)n, nullptr);
        } while (n+'0' != 'q' && n+'0' != 'r');
    }while (n+'0' != 'q');

}
