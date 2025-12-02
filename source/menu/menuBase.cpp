#include "menuBase.hpp"

// Return<MenuOutcome,S> MenuBase::chooseOption(S& output, V<S>& options) {
//     Return<V<S>> content;
//     Return<S> option;
//     output += "(i) Choose Option: ";

//     menuDisplay.clear();
//     menuDisplay.displayHeader(menuName);
//     //content = menuDisplay.displayContent({output});
//     option = Return<S>(content.tCode, content.data[0]);

//     if(option.data.empty() || std::find(options.begin(),options.end(),option.data) == options.end())
//     {
//         return Return<S>(MenuOutcome::FAILURE);
//     }
//     return option;
// }

MenuOutcome MenuBase::chooseSubmenu(S& output) {
    S input;
    output += "(i) Choose Menu: ";

    menuDisplay.clear();
    menuDisplay.displayHeader(menuName);
    //input = menuDisplay.displayContent({output})[0];

    if(input.empty() || !submenus.count(input))
    {
        return MenuOutcome::FAILURE;
    }

    MenuRepository::previousMenus.push(MenuRepository::current);
    MenuRepository::current = submenus[input];

    return MenuOutcome::NONE;
}

Return<MenuOutcome,V<S>> MenuBase::fillForm(V<P<S,B>>& outputs, std::function<void(S&,S&)> actionListener)
{
    Return<MenuOutcome,V<S>> inputs;

    menuDisplay.clear();
    menuDisplay.displayHeader(menuName);
    inputs = menuDisplay.displayContent(outputs, actionListener);

    if(inputs.tCode != MenuOutcome::NONE)
    {
        return inputs;
    }
    MenuRepository::previousMenus.push(MenuRepository::current);
    MenuRepository::current = submenus[""];

    return MenuOutcome::NONE;
}

MenuOutcome MenuBase::wrongInput()
{
    Return<MenuOutcome,V<S>> inputs;
    std::function<void(S& input,S& output)> effect =
    [](S& input, S& output) {
        if(input == " ") return MenuOutcome::NONE;
        else return MenuOutcome::NONE;
    };

    menuDisplay.clear();
    inputs = menuDisplay.displayContent({{"\n\nWrong input. Enter [SPACE] to retry or see [:m;]",false}}, effect);

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
        outputHandler << header << ConsoleCode::NLINE;
}
Return<MenuOutcome,V<S>> MenuDisplay::displayContent(V<P<S,B>> outputs, std::function<void(S&,S&)> effect) {
    //V<S> inputs; w inputHandler

    Return<MenuOutcome,S> inputLine;
    for(auto [output,multiLine] : outputs) {
        outputHandler << output;
        inputLine = inputHandler.getInput(multiLine,effect);

        //if(inputLine.exit()) return Return<V<S>>(inputLine.tCode);

        // inputs.push_back(inputLine.data); w inputHandler
        outputHandler << ConsoleCode::NLINE;
    }
    return Return<MenuOutcome,V<S>>(inputLine.tCode,{});
}
void MenuDisplay::clear() {
    header = content = "";
    outputHandler << ConsoleCode::CLEAR_PAGE;
}
