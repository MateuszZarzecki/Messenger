#include "menuManager.hpp"

MenuManager::MenuManager()
{
    MenuBase::setMenuRepository(menuRepository);
}
MenuManager::~MenuManager()
{}

void MenuManager::display()
{
    while(menuRepository.current)
    {
        menuRepository.current->display();
    }
}


