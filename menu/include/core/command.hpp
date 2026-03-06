#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <conio.h>
#include <functional>

#include "projectBase.hpp"

//enum class MenuOutcome { NONE=-1,FINISH,QUIT };
enum class CommandCode { NONE,FINISH,QUIT,ESCAPE,HOME,MANUAL,BACK,COLON,FIX,FAILURE };

class CommandResolver {
public:
    CommandResolver();

    CommandCode resolveCommand(char character);

private:
    char prefix, sufix;
    UnorderedMap <String, CommandCode> commands;
    String commandInput;
    bool commandInputActive;
};

/*WHat is your name: mateusz
 * Zarzecki imienia nie znam swego
 * drugiego nie mam i figo fago
------------------
:: - : in input printed
:gbn
*/

//POKAZAC ZE WSKAZNIK NA FORWARD DECLARATION WYWOLUJE METODY
