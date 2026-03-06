#include "menuManager.hpp"

MenuManager::MenuManager()
{
    frame->menuLayout = new AuthenticationMenu();
}
void MenuManager::display()
{
    while(frame->menuLayout)
    {
        outputHandler << frame->menuLayout->display();
    }
}
