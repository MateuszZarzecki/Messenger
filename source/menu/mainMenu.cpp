#include "mainMenu.hpp"
#include "chatMenu.hpp"

void MainMenu::init() {
    menuName = "MAIN";
    submenus = {{"1", new ChatMenu()}};
    std::string output = 
        "\n------------ \n"
        "1. Chats \n"
        "2. Friends \n"
        "3. Users \n"
        "4. Settings \n";
    chooseSubmenu(output);
}  
