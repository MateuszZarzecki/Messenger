#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <conio.h>
#include <functional>

#include "projectBase.hpp"
#include "signal.hpp"
#include "consoleUtils.hpp"

class InputHandler {
public:
    InputHandler();

    std::pair<std::string,TerminationCode> getInput(bool multiLine = false);
private:
    //Console console;
    SignalHandler signalHandler;
};
