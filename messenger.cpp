#include <iostream>

#include "authenticationMenu.hpp"
#include "menuBase.hpp"
#include "input.hpp"
#include "output.hpp"
#include "menuManager.hpp"
#include "localUserApi.hpp"

#include <sstream>

#include <limits>
#include "debug.hpp"


/*
 * MOZLIWOSC KORZYSTANIA Z BACKSPACE, STRZALEK DELETE :()
 * -
 * WSZYSTKIE MOZLIWE TYPY ZAMIENIC NA SKROTY - SZYBSZE PISANIE
 *
 * COMMANDS W FOOTER
 *
 * JEDEN MENUCODE / MenuOutcome DO PROCESU POBRANIA DANYCH
 *
 * ACTION LISTENERY MAJA DOSTEP DO CONSOLE - TYLE WYSTARCZY
 * ICH ZADANIE JEST DYNAMICZNE - MAJA UNIEMOZLIWIAC DALSZEGO WPISYWANIA TEKSTU
 * PODKRESLANIA - USUWANIA GO
*/

int main() {

    CharHandler ch;
    InputHandler ih;
    Return<MenuOutcome,S> r = ih.getInput(true);
    return 0;
}
