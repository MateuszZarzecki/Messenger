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
    std::unordered_map<std::string, CommandCode> signals;
    std::unordered_map<CommandCode, TerminationCode> signalTerminations;
    std::unordered_map<CommandCode, TerminationCode(CommandHandler::*)(std::vector<std::string>)> signalResponses;

    // TerminationCode finishSignal(std::vector<std::string> args);
    // TerminationCode quitSignal(std::vector<std::string> args);
    // TerminationCode homeSignal(std::vector<std::string> args);
    // TerminationCode manualSignal(std::vector<std::string> args);
    // TerminationCode backSignal(std::vector<std::string> args);
    // TerminationCode textColorSignal(std::vector<std::string> args);
};
