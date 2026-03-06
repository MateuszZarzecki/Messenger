#include "command.hpp"

CommandResolver::CommandResolver()
{
    prefix = ':', sufix = '\r';
    commandInput = "";
    commandInputActive = false;

    commands = {
        {":", CommandCode::COLON},
        {"fx", CommandCode::FIX}, {"fix", CommandCode::FIX},
        {"fi", CommandCode::FINISH}, {"finish-input", CommandCode::FINISH},
        {"e", CommandCode::ESCAPE}, {"escape", CommandCode::ESCAPE},
        {"q", CommandCode::QUIT}, {"quit", CommandCode::QUIT},
        {"hm", CommandCode::HOME}, {"home", CommandCode::HOME},
        {"h", CommandCode::MANUAL}, {"help", CommandCode::MANUAL},
        {"m", CommandCode::MANUAL}, {"manual", CommandCode::MANUAL},
        {"b", CommandCode::BACK}, {"back", CommandCode::BACK},
    };
}
CommandCode CommandResolver::resolveCommand(char character)
{
    CommandCode result = CommandCode::NONE;
    if(character == prefix)
    {
        commandInputActive = true;
    }
    if(character == sufix)
    {
        if(commands.find(commandInput) != commands.end())
        {
            commandInputActive = false;
            commandInput = "";
            result = commands[commandInput];
        }
        else
        {
            commandInput = "";
            result = CommandCode::FAILURE;
        }
    }
    if(commandInputActive)
    {
        commandInput += character;
    }
    return result;
}
