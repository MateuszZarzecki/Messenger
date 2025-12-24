#pragma once

#include "projectBase.hpp"

class MenuBase;

class MenuRepository
{
public:
    MenuBase* current;
    V<MenuBase*> previousMenus;
};
