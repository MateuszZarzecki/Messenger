#include "input.hpp"

Pair< Pair<char,SpecialKey>, CommandCode> InputHandler::handleInput()
{
    Pair< Pair<char,SpecialKey>, CommandCode> result;

    int key = getch();
    result.first = inputKeyResolver.resolveKey(key);
    result.second = commandResolver.resolveCommand(key);

    return result;
}
