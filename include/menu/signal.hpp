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

struct MenuRepository;

enum class SignalCode { NONE=-1,FINISH,QUIT,HOME,MANUAL,BACK,TEXTCOLOR };

class SignalHandler { 
public: 
    SignalHandler(MenuRepository& menuRepository);

    TerminationCode handleSignals(std::string input);
    std::string unescapePrefixes(std::string input);
private:
    MenuRepository& menuRepository;
    Console console;

    char prefix, postfix, paramChar;
    std::unordered_map<std::string, SignalCode> signals;
    std::unordered_map<SignalCode, TerminationCode> signalTerminations;
    std::unordered_map<SignalCode, TerminationCode(SignalHandler::*)(std::vector<std::string>)> signalResponses;

    TerminationCode finishSignal(std::vector<std::string> args);
    TerminationCode quitSignal(std::vector<std::string> args);
    TerminationCode homeSignal(std::vector<std::string> args);
    TerminationCode manualSignal(std::vector<std::string> args);
    TerminationCode backSignal(std::vector<std::string> args);
    TerminationCode textColorSignal(std::vector<std::string> args);
};
