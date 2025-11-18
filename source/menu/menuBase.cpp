#include "menuBase.hpp"
#include "input.hpp"
#include "consoleUtils.hpp"

Return<S> MenuBase::chooseOption(S& output, V<S>& options) {
    Return<V<S>> content;
    Return<S> option;
    output += "(i) Choose Option: ";

    menuDisplay.clear();
    menuDisplay.displayHeader(menuName);
    //content = menuDisplay.displayContent({output});
    option = Return<S>(content.tCode, content.data[0]);

    if(option.data.empty() || std::find(options.begin(),options.end(),option.data) == options.end())
    {
        return Return<S>(TerminationCode::FAILURE);
    }
    return option;
}
TerminationCode MenuBase::chooseSubmenu(S& output) {
    S input;
    output += "(i) Choose Menu: ";

    menuDisplay.clear();
    menuDisplay.displayHeader(menuName);
    //input = menuDisplay.displayContent({output})[0];

    if(input.empty() || !submenus.count(input))
    {
        return TerminationCode::FAILURE;
    }

    MenuRepository::previousMenus.push(MenuRepository::current);
    MenuRepository::current = submenus[input];

    return TerminationCode::NONE;
}
Return<V<S>> MenuBase::fillForm(V<P<S,B>>& outputs, std::function<TerminationCode(S)> actionListener)
{
    Return<V<S>> inputs;

    menuDisplay.clear();
    menuDisplay.displayHeader(menuName);
    inputs = menuDisplay.displayContent(outputs, actionListener);

    if(!inputs.ok())
    {
        return inputs;
    }
    MenuRepository::previousMenus.push(MenuRepository::current);
    MenuRepository::current = submenus[""];

    return TerminationCode::NONE;
}
TerminationCode MenuBase::wrongInput()
{
    Return<V<S>> inputs;
    std::function<TerminationCode(S)> actionListenerer =
    [](S content) {
        if(content == " ") return TerminationCode::DONE;
        else return TerminationCode::NONE;
    };

    menuDisplay.clear();
    inputs = menuDisplay.displayContent({{"\n\nWrong input. Enter [SPACE] to retry or see [:m;]",false}}, actionListenerer);

    return inputs.tCode;
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
Return<V<S>> MenuDisplay::displayContent(V<P<S,B>> outputs, std::function<TerminationCode(S)> actionListener) {
    V<S> inputs;
    Return<S> inputLine;

    for(auto [output,multiLine] : outputs) {
        console << output;
        inputLine = inputHandler.getInput(multiLine,actionListener);

        if(inputLine.exit()) return Return<V<S>>(inputLine.tCode);

        inputs.push_back(inputLine.data);
        console << ConsoleCode::NLINE;
    }
    return Return<V<S>>(inputLine.tCode,inputs);
}
void MenuDisplay::clear() {
    header = content = "";
    console << ConsoleCode::CLEAR_PAGE;
}
