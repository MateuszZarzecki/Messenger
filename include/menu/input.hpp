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

class CharHandler
{
public:
    CharHandler();

    char process();
    char read();
    void display();
private:
    char buffer;
    OutputHandler outputHandler;
};

class InputHandler {
public:
    InputHandler();

    Return<MenuOutcome,S> getInput(bool multiLine = false, std::function<void(S&,S&)> effect = {});
    void clearInputBuffer();
    S getInputBuffer();
private:
    S inputs;
    OutputHandler outputHandler;
    CharHandler charHandler;
    CommandHandler commandHandler;
};
