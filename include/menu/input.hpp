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

    ReturnData<S> getInput(bool multiLine = false);
private:
    Console console;
    CommandHandler commandHandler;
};
