#include "command.hpp"

CommandHandler::CommandHandler() {

    prefix = ':'; postfix = ';'; paramChar = '=';
    commandsOutcomes = {
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
    commandsResponses = {};
}
MenuOutcome CommandHandler::handleCommands(S input) {

    V<Triplet<CommandCode,size_t,S>> commandsFound = {};
    for(size_t i=1; i<input.size(); i++) {
        if(input[i-1] == prefix && input[i] == prefix) {
            input.erase(i-1,2);
        }
    }

    size_t prefixPos=0,afterCommandNamePos=0,postfixPos=0;
    while(true) {
        S parameter="";

        prefixPos = input.find(prefix,prefixPos);
        if(prefixPos != S::npos)
        {
            postfixPos = input.find(';',prefixPos);
            if(postfixPos != S::npos)
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

                        commandsFound.push_back(Triplet<CommandCode,size_t,S>{code,prefixPos,parameter});
                        prefixPos=postfixPos;
                        break;
                    }
                }
            }
            else { break; }
        }
        else { break; }
    }

    auto comparator = [](Triplet<CommandCode,size_t,S> command1, Triplet<CommandCode,size_t,S> command2){return command1.second < command2.second;};
    std::sort(commandsFound.begin(), commandsFound.end(), comparator);
    for(auto command : commandsFound)
    {
        if(commandsResponses.count(command.first))
        {
            (this->*commandsResponses[command.first])({command.second,command.third});
        }
        if(commandsOutcomes[command.first] != MenuOutcome::NONE)
        {
            return commandsOutcomes[command.first];
        }
    }
    return MenuOutcome::NONE;
}
S CommandHandler::unescapePrefixes(S input) {
    for(int i=1; i<input.size(); i++) {
        if(input[i-1] == prefix && input[i] == prefix) {
            input.erase(i,1);
        }
    } return input;
}
