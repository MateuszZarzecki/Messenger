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

//Termination Codes can be outputed for debug reasons

int main() {

    // MenuManager menuManager;
    // menuManager.display();

    CommandHandler ch;
    Debug::terminationString(ch.handleCommands(":tc:b;"));

    return 0;
}
