#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <conio.h>
#include <functional>

#include "projectBase.hpp"
#include "menuRepository.hpp"

enum class MenuOutcome { NONE=-1,FINISH,QUIT,FAILURE };
enum class CommandCode { NONE=-1,FINISH,QUIT,HOME,MANUAL,BACK };

class CommandHandler {
public:
    CommandHandler(MenuRepository& menuRepository);

    MenuOutcome handleCommands(S input);
    S unescapePrefixes(S input);
private:
    MenuRepository& menuRepository;

    char prefix, postfix, paramChar;
    UM<S, CommandCode> commands;
    UM<CommandCode, MenuOutcome> commandsOutcomes;
    UM<CommandCode, void(CommandHandler::*)(V<S>)> commandsResponses;
};
