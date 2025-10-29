#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <conio.h>
#include <functional>

#include "projectBase.hpp"
#include "consoleUtils.hpp"

enum class CommandCode { NONE=-1,FINISH,QUIT,HOME,MANUAL,BACK,TEXTCOLOR };

class CommandHandler {
public:
    CommandHandler();

    TerminationCode handleCommands(std::string input);
    std::string unescapePrefixes(std::string input);
private:
    //Console console;

    char prefix, postfix, paramChar;
    std::unordered_map<std::string, CommandCode> commands;
    std::unordered_map<CommandCode, TerminationCode> commandsTerminations;
    std::unordered_map<CommandCode, TerminationCode(CommandHandler::*)(std::vector<std::string>)> commandsResponses;

    TerminationCode finishCommand(std::vector<std::string> args);
    TerminationCode quitCommand(std::vector<std::string> args);
    TerminationCode homeCommand(std::vector<std::string> args);
    TerminationCode manualCommand(std::vector<std::string> args);
    TerminationCode backCommand(std::vector<std::string> args);
    TerminationCode textColorCommand(std::vector<std::string> args);
};
