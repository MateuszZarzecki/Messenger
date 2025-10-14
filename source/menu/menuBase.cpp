#include "menuBase.hpp"
#include "input.hpp"
#include "consoleUtils.hpp"


TerminationCode MenuBase::chooseSubmenu(std::string output) {
    console << output;
    MenuRepository::menuDisplay.addHeader(menuName);
    std::pair<std::string,TerminationCode> inputLine = inputHandler.getInput();
    
    if(inputLine.second != TerminationCode::QUIT) {
        if(submenus.count(inputLine.first)) {
            MenuRepository::current = submenus[inputLine.first];
        } else {
            wrongInput();
            return TerminationCode::FAILURE;
        }
    } return inputLine.second;
}
TerminationCode MenuBase::fillForm(std::vector<std::string> outputs, std::vector<std::string> inputs) {
    std::pair<std::string, TerminationCode> inputLine;
    
    for(int i=0; i<(int)outputs.size(); i++) {
        console << outputs[i];
        inputLine = inputHandler.getInput();
        if(inputLine.second != TerminationCode::QUIT) {
            inputs.push_back(inputLine.first);
        }
    } console << ConsoleCode::NLINE;

    MenuRepository::current = submenus[""];
    return inputLine.second;
}
void MenuBase::wrongInput() {
    MenuRepository::menuDisplay.clear();
    MenuRepository::menuDisplay.addContent("\n\nWrong input. Try again or see [:m;]");
    MenuRepository::menuDisplay.display();
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
void MenuDisplay::addContent(std::string newContent) {
    content = newContent;
}
void MenuDisplay::clear() {
    header = content = "";
}
void MenuDisplay::display() {
    console << header << content;
}
//MenuBase* MenuRepository::current = nullptr;

