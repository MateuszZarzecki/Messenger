#include "commands.hpp"

CommandHandler::CommandHandler() {

    prefix = ':'; postfix = ';'; paramChar = '=';
    commandsTerminations = {
        {CommandCode::NONE, MenuOutcome::NONE},
        {CommandCode::MANUAL, MenuOutcome::NONE},
        {CommandCode::TEXTCOLOR, MenuOutcome::NONE},
        {CommandCode::FINISH, MenuOutcome::FINISH},
        {CommandCode::QUIT, MenuOutcome::QUIT},
        {CommandCode::HOME, MenuOutcome::QUIT},
        {CommandCode::BACK, MenuOutcome::QUIT}
    };
    commands = {
        {"f", CommandCode::FINISH}, {"finish", CommandCode::FINISH},
        {"q", CommandCode::QUIT}, {"quit", CommandCode::QUIT},
        {"h", CommandCode::HOME}, {"home", CommandCode::HOME},
        {"m", CommandCode::MANUAL}, {"manual", CommandCode::MANUAL},
        {"b", CommandCode::BACK}, {"back", CommandCode::BACK},
        {"tc", CommandCode::TEXTCOLOR}, {"textcolor", CommandCode::TEXTCOLOR}
    };
    commandsResponses = {
        {CommandCode::TEXTCOLOR, &CommandHandler::textColorCommand},
        {CommandCode::BACK, &CommandHandler::backCommand},
        {CommandCode::QUIT, &CommandHandler::quitCommand}
    };
}
MenuOutcome CommandHandler::handleCommands(std::string input) {

    MenuOutcome terminationCode = MenuOutcome::NONE;
    std::vector<std::tuple<CommandCode,size_t,std::string>> commandsFound;
    for(size_t i=1; i<input.size(); i++) {
        if(input[i-1] == prefix && input[i] == prefix) {
            input.erase(i-1,2);
        }
    }

    size_t prefixPos=0,afterCommandNamePos=0,postfixPos=0;
    while(true) {
        std::string parameter="";
        bool foundCommand = false;

        prefixPos = input.find(prefix,prefixPos);
        if(prefixPos != std::string::npos)
        {
            postfixPos = input.find(';',prefixPos);
            if(postfixPos != std::string::npos)
            {
                if(input.find(':',prefixPos+1) < postfixPos) {
                    return MenuOutcome::FAILURE;
                }
                for(auto [key,code] : commands) {
                    if(input.find(prefix+key,prefixPos) < postfixPos)
                    {
                        afterCommandNamePos = prefixPos + key.size() + 1;
                        if(input[afterCommandNamePos] == '=')
                        {
                            parameter = input.substr(afterCommandNamePos+1,postfixPos-afterCommandNamePos-1);
                        }
                        else if(afterCommandNamePos != postfixPos) { return MenuOutcome::FAILURE; }

                        commandsFound.push_back({code,prefixPos,parameter});
                        prefixPos=postfixPos;
                        foundCommand = true;
                        break;
                    }
                }
                if(!foundCommand)
                {
                    return MenuOutcome::FAILURE;
                }
            }
            else { break; }
        }
        else { break; }
    }

    auto comparator = [](std::tuple<CommandCode,size_t,std::string> signal_1, std::tuple<CommandCode,size_t,std::string> signal_2){return std::get<1>(signal_1) < std::get<1>(signal_2);};
    std::sort(commandsFound.begin(), commandsFound.end(), comparator);
    for(auto command : commandsFound)
    {
        terminationCode = (this->*commandsResponses[std::get<0>(command)])({std::get<1>(command),std::get<2>(command)});
        if(terminationCode == MenuOutcome::QUIT || terminationCode == MenuOutcome::FINISH)
        {
            break;
        }
    }
    return terminationCode;
}
std::string CommandHandler::unescapePrefixes(std::string input) {
    for(int i=1; i<input.size(); i++) {
        if(input[i-1] == prefix && input[i] == prefix) {
            input.erase(i,1);
        }
    } return input;
}
// TerminationCode CommandHandler::finishSignal(std::vector<std::string> args) {
//     return TerminationCode::NONE;
// }
MenuOutcome CommandHandler::quitCommand(std::vector<std::string> args) {
    return MenuOutcome::QUIT;
}
// TerminationCode CommandHandler::homeSignal(std::vector<std::string> args) {
//     return TerminationCode::NONE;
// }
// TerminationCode CommandHandler::manualSignal(std::vector<std::string> args) {
//     return TerminationCode::NONE;
// }
MenuOutcome CommandHandler::backCommand(std::vector<std::string> args) {
    // if(MenuRepository::previousMenus.size() > 0) {
    //     MenuRepository::current = MenuRepository::previousMenus.top();
    //     MenuRepository::previousMenus.pop();
    // }
    return MenuOutcome::QUIT;
}
MenuOutcome CommandHandler::textColorCommand(std::vector<std::string> args) {
    return MenuOutcome::NONE;
}
//signal function 
/*
    signalParameters = {
        {CommandCode::TEXTCOLOR, {"white","black","green","yellow","blue","red","pink","purple","brown"}}
    };
    */
