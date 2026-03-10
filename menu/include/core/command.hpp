#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <conio.h>
#include <functional>

#include "projectBase.hpp"

enum class CommandCode { NONE,FINISH,QUIT,ESCAPE,HOME,MANUAL,BACK,COLON,FIX,FAILURE };

class CommandResolver {
public:
    CommandResolver();

    CommandCode resolveCommand(char character);

private:
    char prefix, sufix;
    UnorderedMap <String, CommandCode> commands;
    String commandInput;
    bool commandInputActive;
};
