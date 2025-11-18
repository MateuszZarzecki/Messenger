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

class MenuDisplay
{
public:
    void clear();

    void displayHeader(S menuName);
    Return<V<S>> displayContent(V<P<S,B>> outputs, std::function<TerminationCode(S)> actionListener = {});
private:
    InputHandler inputHandler;
    Console console;
    S header, content, inputs;
};

class MenuBase
{
public:
    virtual void display() = 0;
protected:
    Console console;
    MenuDisplay menuDisplay;
    InputHandler inputHandler;
    PrimeUser* primeUser;

    S menuName;
    UM<S,MenuBase*> submenus;

    TerminationCode chooseSubmenu(S& output);
    Return<S> chooseOption(S& output, V<S>& options);
    Return<V<S>> fillForm(V<P<S,B>>& outputs, std::function<TerminationCode(S)> actionListener = {});

    TerminationCode wrongInput();
};

namespace MenuRepository
{
    inline MenuBase* current = nullptr;
    inline std::stack<MenuBase*> previousMenus = {};
};



