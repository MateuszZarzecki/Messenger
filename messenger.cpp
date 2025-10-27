#include <iostream>

#include "authenticationMenu.hpp"
#include "menuBase.hpp"
#include "input.hpp"
#include "consoleUtils.hpp"
#include "menuManager.hpp"
#include "localUserApi.hpp"

#include <sstream>

#include <limits>


//Termination Codes can be outputed for debug reasons

int main() {
    CommandHandler ch;
    ch.handleCommands("c::c;:tc=saf:tc=white;");
    // MenuManager menuManager;
    // menuManager.display();
    return 0;
}
