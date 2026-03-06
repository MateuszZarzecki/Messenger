#pragma once
#include <iostream>

#include "authenticationMenu.hpp"
#include "chatMenu.hpp"
#include "mainMenu.hpp"


class MenuManager {
public:
    MenuManager();
    void display();
private:
    Frame* frame;
    Vector <UILayout*> previousMenus;

    InputHandler inputHandler;
    OutputHandler outputHandler;
};
