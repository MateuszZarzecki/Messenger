#include "input.hpp"

InputHandler::InputHandler() {}

Return<S> InputHandler::getInput(bool multiLine){
    TerminationCode commandTerminationCode = TerminationCode::NONE;
    std::string message = "", inputLine = "";
    char character;

    do
    {
        while(true)
        {
            std::string complitedMessage;

            character = ConsoleUtility::getChar();
            inputLine += character;
            complitedMessage = message + inputLine;

            if(character == '\r')
            {
                return Return<S>(TerminationCode::FINISH,complitedMessage.substr(0,complitedMessage.size()-1));
            }
            commandTerminationCode = commandHandler.handleCommands(complitedMessage);
            if(commandTerminationCode != TerminationCode::NONE)
            {
                return commandTerminationCode;
            }
            commandHandler.unescapePrefixes(complitedMessage);

        }
        message += "\n" + inputLine;
    } while(multiLine);

    return Return<S>();
}    
