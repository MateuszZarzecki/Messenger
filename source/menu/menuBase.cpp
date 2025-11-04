#include "menuBase.hpp"
#include "input.hpp"
#include "consoleUtils.hpp"


TerminationCode MenuBase::chooseSubmenu(std::string& output) {
    std::vector<std::string> inputs;
    output += "(i) Choose Menu: ";

    menuDisplay.clear();
    menuDisplay.displayHeader(menuName);
    inputs = menuDisplay.displayContent({output},true);

    if(inputs.empty()) {
        return TerminationCode::QUIT;
    }
    MenuRepository::previousMenus.push(MenuRepository::current);
    MenuRepository::current = submenus[inputs[0]];

    return TerminationCode::NONE;
}
TerminationCode MenuBase::fillForm(std::vector<std::string>& outputs, std::vector<std::string>& inputs) {
    menuDisplay.clear();
    menuDisplay.displayHeader(menuName);
    inputs = menuDisplay.displayContent(outputs,true);

    if(inputs.empty()) {
        return TerminationCode::QUIT;
    }
    MenuRepository::previousMenus.push(MenuRepository::current);
    MenuRepository::current = submenus[""];

    return TerminationCode::NONE;
}
void MenuBase::wrongInput() {
    menuDisplay.clear();
    menuDisplay.displayContent({"\n\nWrong input. Try again or see [:m;]"});
}
void MenuDisplay::displayHeader(std::string menuName) {
        const unsigned int MENU_HEADER_MAX_SIZE = 49;
        unsigned int centerPos = (MENU_HEADER_MAX_SIZE - menuName.size()) / 2;
        std::string menuHeaderCentered = "";

        for(int i=0;i<(int)(MENU_HEADER_MAX_SIZE - menuName.size());i++) {
            menuHeaderCentered += '_';
        }
        menuHeaderCentered.insert(centerPos, menuName);
        
        header +=  "| Messenger | BACK[:b;] - QUIT[:q;] - HOME[:h;] - MANUAL[:m;] |\n"
                  "|___________|"+               menuHeaderCentered            +"|\n";
        console << header << ConsoleCode::NLINE;
}
std::vector<std::string> MenuDisplay::displayContent(std::vector<std::string> outputs, bool lastIsInput) {
    std::vector<std::string> inputs;
    Return<S> inputLine;

    for(int i=0;i<outputs.size();i++) {
        console << outputs[i];
        inputLine = inputHandler.getInput();

        if(inputLine.tCode == TerminationCode::QUIT) {
            return {};
        }
        inputs.push_back(inputLine.data);
        console << ConsoleCode::NLINE;
    }
    return inputs;
}
void MenuDisplay::clear() {
    header = content = "";
    console << ConsoleCode::CLEAR_PAGE;
}
