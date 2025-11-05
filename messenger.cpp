#include <iostream>

#include "authenticationMenu.hpp"
#include "menuBase.hpp"
#include "input.hpp"
#include "consoleUtils.hpp"
#include "menuManager.hpp"
#include "localUserApi.hpp"

#include <sstream>

#include <limits>
#include "debug.hpp"


/*
 * MOZLIWOSC KORZYSTANIA Z BACKSPACE, STRZALEK DELETE :()
 * -
 * WSZYSTKIE MOZLIWE TYPY ZAMIENIC NA SKROTY - SZYBSZE PISANIE
*/
int main() {

    MenuManager menuManager;
    menuManager.display();
    return 0;
}
