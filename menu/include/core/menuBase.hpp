#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include <stack>

#include "projectBase.hpp"
#include "input.hpp"
#include "interactionManager.hpp"
#include "sharedModels.hpp"

class MenuBase
{
public:
    virtual void display() = 0;
protected:

    InteractionManager interactionManager;

    PrimeUser* primeUser;

    S menuName;
    UM<S,MenuBase*> submenus;

    MenuOutcome chooseSubmenu(S& output);
    Return<MenuOutcome,S> chooseOption(S& output, V<S>& options);
    Return<MenuOutcome,V<S>> fillForm(V<P<S,B>>& outputs, V<std::function<void(S&,S&)>> effects = {});

    MenuOutcome wrongInput();
    S getHeader();
};

namespace MenuRepository
{
    inline MenuBase* current = nullptr;
    inline std::stack<MenuBase*> previousMenus = {};
};
