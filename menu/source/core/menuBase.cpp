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

MenuOutcome MenuBase::chooseSubmenu(S& output)
{
    Return<MenuOutcome,V<S>> input;
    S header = getHeader();
    output = header + output + "(i) Choose Menu: ";

    input = interactionManager.interact({{output,false}},true);

    if(input.outcome != MenuOutcome::NONE && input.outcome != MenuOutcome::FINISH)
    {
        return input.outcome;
    }
    if(!submenus.count(input.data[0]))
    {
        return MenuOutcome::FAILURE;
    }

    MenuRepository::previousMenus.push(MenuRepository::current);
    MenuRepository::current = submenus[input.data[0]];

    return MenuOutcome::NONE;
}

Return<MenuOutcome,V<S>> MenuBase::fillForm(V<P<S,B>>& outputs, V<std::function<void(S&,S&)>> effects)
{
    Return<MenuOutcome,V<S>> inputs;

    S header = getHeader();
    outputs[0].first = header + outputs[0].first;

    inputs = interactionManager.interact(outputs,true);

    if(inputs.outcome != MenuOutcome::NONE)
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
    std::function<void(S& input,S& _)> effect =
    [](S& input, S& _) {
        if(input == " ") return MenuOutcome::NONE;
        else return MenuOutcome::NONE;
    };

    inputs = interactionManager.interact({{"\n\nWrong input. Enter [SPACE] to retry or see [:m;]",false}},true);
    return inputs.outcome;
}
S MenuBase::getHeader()
{
    OutputString outputOString, headerOString;

    const unsigned int MENU_HEADER_MAX_SIZE = 49;
    unsigned int centerPos = (MENU_HEADER_MAX_SIZE - menuName.size()) / 2;
    std::string menuHeaderCentered = "";

    for(int i=0;i<(int)(MENU_HEADER_MAX_SIZE - menuName.size());i++) {
        menuHeaderCentered += '_';
    }
    menuHeaderCentered.insert(centerPos, menuName);

    headerOString <<  "| Messenger | BACK[:b;] - QUIT[:q;] - HOME[:h;] - MANUAL[:m;] |\n"
                      "|___________|"<<              menuHeaderCentered           <<"|\n";
    outputOString << headerOString << ConsoleCode::NLINE;
    return outputOString.getString();
}
