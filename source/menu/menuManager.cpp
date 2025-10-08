#include "menuManager.hpp"

MenuManager::MenuManager() {
    MenuBase::setMenuRepository(&menuRepository);
    menuRepository.current = new AuthenticationMenu();
}
MenuManager::~MenuManager() {
    // delete menuRepository.current;
    // for(auto [menu,key] : menuRepository.menus) {
    //     delete menu;
    // }
}
void MenuManager::display() {
    while(menuRepository.current) {
        menuRepository.current->init();
    }
} 
