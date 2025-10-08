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

struct MenuRepository;

class InputHandler {
public:
    InputHandler();

    static void setMenuRepository(MenuRepository* menuRepository);
    std::pair<std::string,TerminationCode> getInput(bool multiLine = false);
private:
    static MenuRepository* menuRepository;
    SignalHandler signalHandler;
    Console console;
};
