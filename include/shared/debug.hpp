#pragma once
#include "consoleUtils.hpp"
#include "projectBase.hpp"

class Debug
{
public:
    static void terminationString(TerminationCode terminationCode);
private:
    inline static Console console;
};
