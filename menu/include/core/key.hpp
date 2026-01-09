#pragma once

#include "projectBase.hpp"

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
    V<V<S>>& inputs;
    P<I,I>& cursorPosition;
    B signatureKey;

    SpecialKey handleSpecialKey(I specialKey);
    void handlePrintableKey(I printableKey);
};

class OutputKeyHandler
{
public:
    OutputKeyHandler();
private:
};
