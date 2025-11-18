#include "input.hpp"

InputHandler::InputHandler() {}

Return<S> InputHandler::getInput(bool multiLine, std::function<TerminationCode(S)> actionListener){
    TerminationCode commandTCode, conditionTCode;
    Return<S> combinedReturn;
    std::string message = "", inputLine = "", complitedMessage = "";
    char character;

    do
    {
        while(true)
        {

            character = ConsoleUtility::getChar();
            inputLine += character;
            complitedMessage = message + inputLine;

            if(character == '\r') { break; }

            commandTCode = commandHandler.handleCommands(complitedMessage);
            commandHandler.unescapePrefixes(complitedMessage);
            conditionTCode = actionListener(complitedMessage);

            combinedReturn = combinedReturn.merge({{commandTCode},{conditionTCode}});

            if(!combinedReturn.ok())
            {
                combinedReturn.data = complitedMessage;
                return combinedReturn;
            }
        }
        if(!multiLine)
        {
            return Return<S>(combinedReturn.tCode,complitedMessage.substr(0,complitedMessage.size()-1));
        }
        message += "\n" + inputLine;
        inputLine = "";
    } while(multiLine);

    return Return<S>();
}
