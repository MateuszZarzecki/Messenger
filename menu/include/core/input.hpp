#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <conio.h>
#include <functional>

#include "menuRepository.hpp"
#include "projectBase.hpp"
#include "command.hpp"
#include "key.hpp"

//KEY - RAW SINGLE INPUT
//CHARACTER - PRINTABLE PROCESSED SINGLE INPUT

class InputHandler
{
public:
    InputHandler();
    Pair< Pair<char,SpecialKey>, CommandCode> handleInput();

private:
    InputKeyResolver inputKeyResolver;
    CommandResolver commandResolver;
};

