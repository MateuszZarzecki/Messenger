#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <conio.h>
#include <functional>

#include "projectBase.hpp"
#include "commands.hpp"
#include "consoleUtils.hpp"

class InputHandler {
public:
    InputHandler();

    Return<S> getInput(bool multiLine = false, std::function<TerminationCode(std::string)> actionListener = {});
private:
    Console console;
    CommandHandler commandHandler;
};
