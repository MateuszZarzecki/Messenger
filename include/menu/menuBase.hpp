#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>

#include "projectBase.hpp"
#include "input.hpp"
#include "consoleUtils.hpp"
#include "sharedModels.hpp"
#include "stack"

class MenuDisplay {
public:
    void clear();

    void displayHeader(std::string menuName);
    std::vector<std::string> displayContent(std::vector<std::string> outputs, bool lastIsInput=false);
private:
    InputHandler inputHandler;
    Console console;
    std::string header, content, inputs;
};

class MenuBase {
public:
    virtual void display() = 0;
protected:
    Console console;
    MenuDisplay menuDisplay;
    InputHandler inputHandler;
    PrimeUser* primeUser;

    std::string menuName;
    std::unordered_map<std::string,MenuBase*> submenus;

    Return<I> chooseOption(std::string& output);
    TerminationCode chooseSubmenu(V<P<S,S>>& output);
    TerminationCode fillForm(std::vector<std::string>& outputs, std::vector<std::string>& inputs);

    void wrongInput();
};

namespace MenuRepository
{
    inline MenuBase* current = nullptr;
    inline std::stack<MenuBase*> previousMenus = {};
};



