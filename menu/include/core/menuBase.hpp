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
#include "menuRepository.hpp"

class MenuBase
{
public:
    virtual void display() = 0;
    static void setMenuRepository(MenuRepository& menuRepository);
protected:
    static inline MenuRepository* menuRepository = nullptr;
    static inline InteractionManager* interactionManager = nullptr;

    PrimeUser* primeUser;

    S menuName;
    UM<S,MenuBase*> submenus;

    MenuOutcome chooseSubmenu(S& output);
    Return<MenuOutcome,S> chooseOption(S& output, V<S>& options);
    Return<MenuOutcome,V<S>> fillForm(V<P<S,B>>& outputs, V<std::function<void(S&,S&)>> effects = {});

    MenuOutcome wrongInput();
    S getHeader();
};


