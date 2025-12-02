#include "input.hpp"

CharHandler::CharHandler()
    : buffer(0) {}

char CharHandler::process()
{
    buffer = getch();
    display();
    return buffer;
}
char CharHandler::read()
{
    buffer = getch();
    return buffer;
}
void CharHandler::display()
{
    if(buffer == '\r')
        outputHandler << ConsoleCode::NLINE;
    else
        outputHandler << buffer;
}

InputHandler::InputHandler() {}


Return<MenuOutcome,S> InputHandler::getInput(bool multiLine, std::function<void(S&,S&)> effect){
    MenuOutcome commandTCode, conditionTCode;
    Return<MenuOutcome,S> combinedReturn;
    std::string message = "", inputLine = "", complitedMessage = "";
    char character;

    do
    {
        while(true)
        {
            character = charHandler.process();
            inputLine += character;
            complitedMessage = message + inputLine;

            if(character == '\r') { break; }

            commandTCode = commandHandler.handleCommands(complitedMessage);
            commandHandler.unescapePrefixes(complitedMessage);

            S outputs = outputHandler.getOutputBuffer();
            effect(inputs,outputs);

            if(combinedReturn.tCode != MenuOutcome::NONE)
            {
                combinedReturn.data = complitedMessage;
                return combinedReturn;
            }
        }
        if(!multiLine)
        {
            return Return<MenuOutcome,S>(combinedReturn.tCode,complitedMessage.substr(0,complitedMessage.size()-1));
        }
        message += "\n" + inputLine;
        inputLine = "";
    } while(multiLine);

    return Return<MenuOutcome,S>();
}
