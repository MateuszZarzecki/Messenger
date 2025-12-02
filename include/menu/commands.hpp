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

enum class CommandCode { NONE=-1,FINISH,QUIT,HOME,MANUAL,BACK,TEXTCOLOR };

class CommandHandler {
public:
    CommandHandler();

    MenuOutcome handleCommands(std::string input);
    std::string unescapePrefixes(std::string input);
private:
    OutputHandler outputHandler;

    char prefix, postfix, paramChar;
    std::unordered_map<std::string, CommandCode> commands;
    std::unordered_map<CommandCode, MenuOutcome> commandsTerminations;
    std::unordered_map<CommandCode, MenuOutcome(CommandHandler::*)(std::vector<std::string>)> commandsResponses;

    MenuOutcome finishCommand(std::vector<std::string> args);
    MenuOutcome quitCommand(std::vector<std::string> args);
    MenuOutcome homeCommand(std::vector<std::string> args);
    MenuOutcome manualCommand(std::vector<std::string> args);
    MenuOutcome backCommand(std::vector<std::string> args);
    MenuOutcome textColorCommand(std::vector<std::string> args);
};
