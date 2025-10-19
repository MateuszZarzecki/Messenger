#include "signal.hpp"
#include "consoleUtils.hpp"
#include "menuBase.hpp"

SignalHandler::SignalHandler() {

    prefix = ':'; postfix = ';'; paramChar = '=';
    signalTerminations = {
        {SignalCode::NONE, TerminationCode::NONE},
        {SignalCode::MANUAL, TerminationCode::NONE},
        {SignalCode::TEXTCOLOR, TerminationCode::NONE},
        {SignalCode::FINISH, TerminationCode::FINISH},
        {SignalCode::QUIT, TerminationCode::QUIT},
        {SignalCode::HOME, TerminationCode::QUIT},
        {SignalCode::BACK, TerminationCode::QUIT}
    };
    signals = {
        {"f", SignalCode::FINISH}, {"finish", SignalCode::FINISH},
        {"q", SignalCode::QUIT}, {"quit", SignalCode::QUIT},
        {"h", SignalCode::HOME}, {"home", SignalCode::HOME},
        {"m", SignalCode::MANUAL}, {"manual", SignalCode::MANUAL},
        {"b", SignalCode::BACK}, {"back", SignalCode::BACK},
        {"tc", SignalCode::TEXTCOLOR}, {"textcolor", SignalCode::TEXTCOLOR}
    };
}
TerminationCode SignalHandler::handleSignals(std::string input) { 
    //asdnbc::c;:c=:c=white;
    //asdnbcc;:c=:c=white;

    //json as signals
    TerminationCode terminationCode = TerminationCode::NONE;
    std::vector<std::tuple<SignalCode,size_t,std::string>> signalsFound;
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
    auto comparator = [](std::tuple<SignalCode,size_t,std::string> signal_1, std::tuple<SignalCode,size_t,std::string> signal_2){return std::get<1>(signal_1) < std::get<1>(signal_2);}; 
    std::sort(signalsFound.begin(), signalsFound.end(), comparator);
    for(auto signal : signalsFound) {
        terminationCode = (this->*signalResponses[std::get<0>(signal)])({std::get<1>(signal),std::get<2>(signal)});
        if(terminationCode == TerminationCode::FAILURE) {
            return TerminationCode::FAILURE;
        }
    }
    return terminationCode;
}
std::string SignalHandler::unescapePrefixes(std::string input) {
    for(int i=1; i<input.size(); i++) {
        if(input[i-1] == prefix && input[i] == prefix) {
            input.erase(i,1);
        }
    } return input;
}
TerminationCode SignalHandler::finishSignal(std::vector<std::string> args) {
    return TerminationCode::NONE;
}
TerminationCode SignalHandler::quitSignal(std::vector<std::string> args) {
    return TerminationCode::NONE;
}
TerminationCode SignalHandler::homeSignal(std::vector<std::string> args) {
    return TerminationCode::NONE;
}
TerminationCode SignalHandler::manualSignal(std::vector<std::string> args) {
    return TerminationCode::NONE;
}
TerminationCode SignalHandler::backSignal(std::vector<std::string> args) {
    if(MenuRepository::previousMenus.size() > 0) {
        MenuRepository::current = MenuRepository::previousMenus.top();
        MenuRepository::previousMenus.pop();
    }
    return TerminationCode::NONE;
}
TerminationCode SignalHandler::textColorSignal(std::vector<std::string> args) {
    return TerminationCode::NONE;
}
//signal function 
/*
    signalParameters = {
        {SignalCode::TEXTCOLOR, {"white","black","green","yellow","blue","red","pink","purple","brown"}}
    };
    */
