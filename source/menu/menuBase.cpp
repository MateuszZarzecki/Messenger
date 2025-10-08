#include "menuBase.hpp"
#include "input.hpp"
#include "consoleUtils.hpp"

MenuRepository* MenuBase::menuRepository = nullptr;

void MenuBase::setMenuRepository(MenuRepository* menuRepository) {
    MenuBase::menuRepository = menuRepository;
    InputHandler::setMenuRepository(menuRepository);
}
TerminationCode MenuBase::chooseSubmenu(std::string output) {
    std::cout << output;
    menuRepository->menuDisplay.addHeader(menuName);
    std::pair<std::string,TerminationCode> inputLine = inputHandler.getInput();
    
    if(inputLine.second != TerminationCode::QUIT) {
        if(submenus.count(inputLine.first)) {
            menuRepository->current = submenus[inputLine.first];
        } else {
            wrongInput();
            return TerminationCode::FAILURE;
        }
    } return inputLine.second;
}
TerminationCode MenuBase::fillForm(std::vector<std::string> outputs, std::vector<std::string> inputs) {
    std::pair<std::string, TerminationCode> inputLine;
    
    for(int i=0; i<(int)outputs.size(); i++) {
        std::cout << outputs[i];
        inputLine = inputHandler.getInput();
        if(inputLine.second != TerminationCode::QUIT) {
            inputs.push_back(inputLine.first);
        }
    } std::cout << std::endl;

    menuRepository->current = submenus[""];
    return inputLine.second;
}
void MenuBase::wrongInput() {
    menuRepository->menuDisplay.clear();
    menuRepository->menuDisplay.addContent("Wrong input. Try again or see [:m;]");
    menuRepository->menuDisplay.display();
}

void MenuDisplay::addHeader(std::string menuName) {
        const unsigned int MENU_HEADER_MAX_SIZE = 49;
        unsigned int centerPos = (MENU_HEADER_MAX_SIZE - menuName.size()) / 2;
        std::string menuHeaderCentered = "";

        for(int i=0;i<(int)(MENU_HEADER_MAX_SIZE - menuName.size());i++) {
            menuHeaderCentered += '_';
        }
        menuHeaderCentered.insert(centerPos, menuName);
        
       header +=  "| Messenger | BACK[:b;] - QUIT[:q;] - HOME[:h;] - MANUAL[:m;] |\n"
                  "|___________|"+               menuHeaderCentered            +"|\n\n";
}
void MenuDisplay::addContent(std::string content) {
    this->content += content;
}
void MenuDisplay::clear() {
    header = content = "";
}
void MenuDisplay::display() {
    std::cout << header << content << "\n";
}
MenuRepository::MenuRepository() {

}
