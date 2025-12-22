#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <conio.h>
#include <functional>

#include "projectBase.hpp"
#include "command.hpp"

//KEY - RAW SINGLE INPUT
//CHARACTER - PRINTABLE PROCESSED SINGLE INPUT

//ADD TO OUTPUT.hpp
enum class SpecialKey
{
    NONE=-1,
    BACKSPACE,COLON,SEMICOLON,TAB,ENTER,DELETE,
    ARROW_LEFT,ARROW_TOP,ARROW_RIGHT,ARROW_DOWN,
    LINE_HOME,LINE_END,MULTILINE_HOME,MULTILINE_END,
    PAGE_UP_CURSOR,PAGE_DOWN_CURSOR,PAGE_UP_VIEW,PAGE_DOWN_VIEW
};

class InputKeyHandler
{
public:
    InputKeyHandler(V<V<S>>& inputs, P<I,I>& cursorPosition);

    P<C,SpecialKey> handleKey(I key);

    static const bool SIGNATURE;
private:
    B signatureKey;
    V<V<S>> inputs;
    P<I,I> cursorPosition;

    SpecialKey handleSpecialKey(I specialKey);
    void handlePrintableKey(I printableKey);
};

//COMMANDHANDLER CZYTAJACY WSZYSTKO JEST POTRZEBNY DO PRZECHODZENIA MIEDZY MENU

class InputHandler {
public:
    InputHandler();

    Return<MenuOutcome,P<C,SpecialKey>> processInput();

    V<V<S>> getInputs();
    void setInputs(V<V<S>> inputs);

    void newInputPage();
    void setMultilineInput(B isMultiline);

    void setEffects(V<P<std::function<void(S&)>,I>> effects);
    void clearEffects();

private:
    B multiline;
    V<V<S>> inputs;
    P<I,I> cursorPosition;

    InputKeyHandler inputKeyHandler;
    CommandHandler commandHandler;
    V<P<std::function<void(S&)>,I>> effects;
};
