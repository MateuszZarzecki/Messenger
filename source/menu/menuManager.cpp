#include "menuManager.hpp"

MenuManager::MenuManager() {
    MenuRepository::current = new AuthenticationMenu();
}
MenuManager::~MenuManager() {
    // delete menuRepository.current;
    // for(auto [menu,key] : menuRepository.menus) {
    //     delete menu;
    // }
}
void MenuManager::display() {

    while(MenuRepository::current) {
        MenuRepository::current->init();

        // if(sygnal == ) {
        //     return;
        // }
        // MenuRepository::current->loop();
    }
} 
