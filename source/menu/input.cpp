#include "input.hpp"

InputHandler::InputHandler() {}

ReturnData<S> InputHandler::getInput(bool multiLine){
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
                    return ReturnData<S>(complitedMessage.substr(0,complitedMessage.size()-1));
                }
                commandHandler.handleCommands(complitedMessage);
                commandHandler.unescapePrefixes(complitedMessage);
            }
        }
        message += "\n" + inputLine;
    } while(multiLine);

    while(true) {
        {
            std::string complitedMessage;

            character = std::cin.get();
            inputLine += character;
            complitedMessage = message + inputLine;

            //shirt enter new line
            //\n finish
            if(character == '\n') {
                return ReturnData<S>(complitedMessage.substr(0,complitedMessage.size()-1));
            }
        }
    }
    //goto Finish;
    // checkSignal(input);
    // current = ...

    return ReturnData<S>();
}    
