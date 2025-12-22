#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <conio.h>
#include <functional>

#include "output.hpp"
#include "projectBase.hpp"

enum class MenuOutcome { NONE=-1,FINISH,QUIT,FAILURE };
enum class CommandCode { NONE=-1,FINISH,QUIT,HOME,MANUAL,BACK,TEXTCOLOR };

class CommandHandler {
public:
    CommandHandler();

    MenuOutcome handleCommands(S input);
    S unescapePrefixes(S input);
private:
    OutputHandler outputHandler;

    char prefix, postfix, paramChar;
    UM<S, CommandCode> commands;
    UM<CommandCode, MenuOutcome> commandsOutcomes;
    UM<CommandCode, void(CommandHandler::*)(V<S>)> commandsResponses;
};
