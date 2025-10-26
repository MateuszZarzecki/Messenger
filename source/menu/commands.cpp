#include "commands.hpp"
#include "consoleUtils.hpp"
#include "menuBase.hpp"

CommandHandler::CommandHandler() {

    prefix = ':'; postfix = ';'; paramChar = '=';
    signalTerminations = {
        {CommandCode::NONE, TerminationCode::NONE},
        {CommandCode::MANUAL, TerminationCode::NONE},
        {CommandCode::TEXTCOLOR, TerminationCode::NONE},
        {CommandCode::FINISH, TerminationCode::FINISH},
        {CommandCode::QUIT, TerminationCode::QUIT},
        {CommandCode::HOME, TerminationCode::QUIT},
        {CommandCode::BACK, TerminationCode::QUIT}
    };
    signals = {
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

    //json as signals
    TerminationCode terminationCode = TerminationCode::NONE;
    std::vector<std::tuple<CommandCode,size_t,std::string>> signalsFound;
    for(int i=1; i<input.size(); i++) {
        if(input[i-1] == prefix && input[i] == prefix) {
            input.erase(i-1,2);
        }
    }
    for(auto [key,value] : signals) {
        size_t signalPrefixPos=0, signalPostfixPos=0;
        std::string parameter="";
        while(true) {
            signalPrefixPos = input.substr(signalPrefixPos).find(prefix+key+paramChar); 
            if(signalPrefixPos != std::string::npos) {
                signalPostfixPos = input.substr(signalPrefixPos+3).find(postfix);
                if(signalPostfixPos != std::string::npos) {
                    parameter = input.substr(signalPrefixPos+3,signalPostfixPos);
                    signalsFound.push_back({value,signalPrefixPos,parameter});
                }
            }
        }
    }
    auto comparator = [](std::tuple<CommandCode,size_t,std::string> signal_1, std::tuple<CommandCode,size_t,std::string> signal_2){return std::get<1>(signal_1) < std::get<1>(signal_2);};
    std::sort(signalsFound.begin(), signalsFound.end(), comparator);
    for(auto signal : signalsFound) {
        terminationCode = (this->*signalResponses[std::get<0>(signal)])({std::get<1>(signal),std::get<2>(signal)});
        if(terminationCode == TerminationCode::FAILURE) {
            return TerminationCode::FAILURE;
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
