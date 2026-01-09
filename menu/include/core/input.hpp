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
#include "effect.hpp"

//KEY - RAW SINGLE INPUT
//CHARACTER - PRINTABLE PROCESSED SINGLE INPUT

//COMMANDHANDLER CZYTAJACY WSZYSTKO JEST POTRZEBNY DO PRZECHODZENIA MIEDZY MENU

class MessageComposer
{

};

class InputHandler
{
public:
    InputHandler(MenuRepository& menuRepository);

    Return<MenuOutcome,P<C,SpecialKey>> processInput();

    V<V<S>>& getInputs();

    void setInputs(V<V<S>> inputs);

    void newPage();
    void setMultilineInput(B isMultiline);

private:
    V<V<S>> inputs;
    P<I,I> cursorPosition;
    B multiline;

    InputKeyHandler inputKeyHandler;
    CommandHandler commandHandler;
    MessageComposer messageComposer;
};

