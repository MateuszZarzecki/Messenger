#include "input.hpp"

Triplet<bool,char,SpecialKey> InputHandler::handleInput()
{
    Triplet<bool,char,SpecialKey> result;
    result.first = false;

    if(_kbhit())
    {
        int key = getch();
        result.first = true;

        Pair<char,SpecialKey> resolvedKey = inputKeyResolver.resolveKey(key);
        result.second = resolvedKey.first;
        result.third = resolvedKey.second;
    }
    return result;
}
