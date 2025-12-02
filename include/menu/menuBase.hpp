#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>

#include "projectBase.hpp"
#include "input.hpp"
#include "output.hpp"
#include "sharedModels.hpp"
#include "stack"


class MenuDisplay
{
public:
    void clear();
    void displayHeader(S menuName);
    Return<MenuOutcome,V<S>> displayContent(V<P<S,B>> outputs, std::function<void(S&,S&)> effect = {});
private:
    InputHandler inputHandler;
    OutputHandler outputHandler;
    S header, content, inputs;
};

class MenuBase
{
public:
    virtual void display() = 0;
protected:
    OutputHandler outputHandler;
    InputHandler inputHandler;

    MenuDisplay menuDisplay;
    PrimeUser* primeUser;

    S menuName;
    UM<S,MenuBase*> submenus;

    MenuOutcome chooseSubmenu(S& output);
    Return<MenuOutcome,S> chooseOption(S& output, V<S>& options);
    Return<MenuOutcome,V<S>> fillForm(V<P<S,B>>& outputs,std::function<void(S&,S&)> effect = {});

    MenuOutcome wrongInput();
};

namespace MenuRepository
{
    inline MenuBase* current = nullptr;
    inline std::stack<MenuBase*> previousMenus = {};
};
