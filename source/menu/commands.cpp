#include "commands.hpp"
#include "consoleUtils.hpp"
#include "menuBase.hpp"

CommandHandler::CommandHandler() {

    prefix = ':'; postfix = ';'; paramChar = '=';
    commandsTerminations = {
        {CommandCode::NONE, TerminationCode::NONE},
        {CommandCode::MANUAL, TerminationCode::NONE},
        {CommandCode::TEXTCOLOR, TerminationCode::NONE},
        {CommandCode::FINISH, TerminationCode::FINISH},
        {CommandCode::QUIT, TerminationCode::QUIT},
        {CommandCode::HOME, TerminationCode::QUIT},
        {CommandCode::BACK, TerminationCode::QUIT}
    };
    commands = {
        {"f", CommandCode::FINISH}, {"finish", CommandCode::FINISH},
        {"q", CommandCode::QUIT}, {"quit", CommandCode::QUIT},
        {"h", CommandCode::HOME}, {"home", CommandCode::HOME},
        {"m", CommandCode::MANUAL}, {"manual", CommandCode::MANUAL},
        {"b", CommandCode::BACK}, {"back", CommandCode::BACK},
        {"tc", CommandCode::TEXTCOLOR}, {"textcolor", CommandCode::TEXTCOLOR}
    };
}
TerminationCode CommandHandler::handleCommands(std::string input) {
    //asdnbc::c;:c=:c=white;
    //asdnbcc;:c=:c=white;

    //DONT USE SUBSTR - ISSUE OF POSITIONING CHARS
    //USE FIND WITH POS ARGUMENT

    TerminationCode terminationCode = TerminationCode::NONE;
    std::vector<std::tuple<CommandCode,size_t,std::string>> commandsFound;
    for(size_t i=1; i<input.size(); i++) {
        if(input[i-1] == prefix && input[i] == prefix) {
            input.erase(i-1,2);
        }
    }
    for(auto [key,code] : commands) {
        size_t commandPos=0,afterCommandNamePos=0,postfixPos=0;
        while(true) {
            std::string parameter="";

            commandPos = input.substr(commandPos).find(prefix+key);
            if(commandPos != std::string::npos) {
                afterCommandNamePos = commandPos+key.size()+1;
                postfixPos = input.substr(afterCommandNamePos).find(';') + afterCommandNamePos;
                if(postfixPos != std::string::npos) {
                    if(input[afterCommandNamePos] == '=') {
                        parameter = input.substr(afterCommandNamePos+1,postfixPos-afterCommandNamePos-1);
                    }
                    else { break; }

                    commandsFound.push_back({code,commandPos,parameter});
                    commandPos++;
                }
                else { break; }
            }
            else { break; }
        }
    }
    // auto comparator = [](std::tuple<CommandCode,size_t,std::string> signal_1, std::tuple<CommandCode,size_t,std::string> signal_2){return std::get<1>(signal_1) < std::get<1>(signal_2);};
    // std::sort(commandsFound.begin(), commandsFound.end(), comparator);
    // for(auto command : commandsFound) {
    //     terminationCode = (this->*commandsResponses[std::get<0>(command)])({std::get<1>(command),std::get<2>(command)});
    //     if(terminationCode == TerminationCode::QUIT || terminationCode == TerminationCode::FINISH) {
    //         break;
    //     }
    // }
    return TerminationCode::NONE;
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
// TerminationCode CommandHandler::quitSignal(std::vector<std::string> args) {
//     return TerminationCode::NONE;
// }
// TerminationCode CommandHandler::homeSignal(std::vector<std::string> args) {
//     return TerminationCode::NONE;
// }
// TerminationCode CommandHandler::manualSignal(std::vector<std::string> args) {
//     return TerminationCode::NONE;
// }
// TerminationCode CommandHandler::backSignal(std::vector<std::string> args) {
//     if(MenuRepository::previousMenus.size() > 0) {
//         MenuRepository::current = MenuRepository::previousMenus.top();
//         MenuRepository::previousMenus.pop();
//     }
//     return TerminationCode::NONE;
// }
// TerminationCode CommandHandler::textColorSignal(std::vector<std::string> args) {
//     return TerminationCode::NONE;
// }
//signal function 
/*
    signalParameters = {
        {CommandCode::TEXTCOLOR, {"white","black","green","yellow","blue","red","pink","purple","brown"}}
    };
    */
