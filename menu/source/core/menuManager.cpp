#include "menuManager.hpp"

MenuManager::MenuManager()
{
    MenuRepository::current = new AuthenticationMenu();
}
MenuManager::~MenuManager()
{

}
void MenuManager::display()
{
    while(MenuRepository::current)
    {
        MenuRepository::current->display();
    }
} 
