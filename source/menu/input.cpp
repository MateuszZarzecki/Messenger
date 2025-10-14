#include "input.hpp"

InputHandler::InputHandler() {}

std::pair<std::string,TerminationCode> InputHandler::getInput(bool multiLine){
    std::string message = "", inputLine = "";
    char character;
    do {
        while(true) {
            {
                std::string complitedMessage;

                character = std::cin.get();
                inputLine += character;
                complitedMessage = message + inputLine;

                if(character == '\n') {
                    return {complitedMessage.substr(0,complitedMessage.size()-1), TerminationCode::NONE};
                }
                // signalHandler.handleSignals(message);
                // signalHandler.unescapePrefixes(message);
            }
        }
        message += "\n" + inputLine;
    } while(multiLine);
    return {};
}    
