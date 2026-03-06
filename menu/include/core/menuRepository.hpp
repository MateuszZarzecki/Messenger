#pragma once

#include "projectBase.hpp"

class MenuBase;

class MenuRepository
{
public:
    MenuBase* current;
    Vector <MenuBase*> previousMenus;
};
