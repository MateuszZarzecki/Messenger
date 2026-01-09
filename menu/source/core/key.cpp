#include "key.hpp"

const bool InputKeyHandler::SIGNATURE = true;

InputKeyHandler::InputKeyHandler(V<V<S>>& inputs, P<I,I>& cursorPosition)
    : inputs(inputs), cursorPosition(cursorPosition) {}

P<C,SpecialKey> InputKeyHandler::handleKey(I key)
{
    P<C,SpecialKey> result = {'\0',SpecialKey::NONE};

    P<I,I> printableKeysRange = {32,126};
    V<P<I,SpecialKey>> specialPrintableKeys = {{58,SpecialKey::COLON}};

    if(printableKeysRange.first <= key && key <= printableKeysRange.second)
    {
        result.first = (C)key;
        for(P<I,SpecialKey> specialKey : specialPrintableKeys)
        {
            if(key == specialKey.first)
            {
                result.second = specialKey.second;
                break;
            }
        }
    }
    SpecialKey specialKey = handleSpecialKey(key);
    result.second = specialKey;

    if(result.first != '\0')
    {
        C character = key;
        S& currentInput = inputs.back().back();

        currentInput.insert(cursorPosition.second,std::to_string(character));
        cursorPosition.second++;
    }

    return result;
}
SpecialKey InputKeyHandler::handleSpecialKey(int key)
{
    P<I,I> extendedKeysSignatures = {0,224};

    M<P<B,I>,SpecialKey> specialKeys =
    {
        {{!SIGNATURE,8},SpecialKey::BACKSPACE},
        {{!SIGNATURE,58},SpecialKey::COLON},
        {{!SIGNATURE,59},SpecialKey::SEMICOLON},
        {{!SIGNATURE,9},SpecialKey::TAB},
        {{!SIGNATURE,13},SpecialKey::ENTER},

        {{SIGNATURE,83},SpecialKey::DELETE},
        {{SIGNATURE,75},SpecialKey::ARROW_LEFT},
        {{SIGNATURE,72},SpecialKey::ARROW_TOP},
        {{SIGNATURE,77},SpecialKey::ARROW_RIGHT},
        {{SIGNATURE,80},SpecialKey::ARROW_DOWN},
        {{SIGNATURE,71},SpecialKey::LINE_HOME},
        {{SIGNATURE,79},SpecialKey::LINE_END},
        {{SIGNATURE,119},SpecialKey::MULTILINE_HOME},
        {{SIGNATURE,117},SpecialKey::MULTILINE_END},
        {{SIGNATURE,73},SpecialKey::PAGE_UP_CURSOR},
        {{SIGNATURE,81},SpecialKey::PAGE_DOWN_CURSOR},
        {{SIGNATURE,134},SpecialKey::PAGE_UP_VIEW},
        {{SIGNATURE,118},SpecialKey::PAGE_DOWN_VIEW},
    };

    if(key == extendedKeysSignatures.first || key == extendedKeysSignatures.second)
    {
        return SpecialKey::NONE;
    }
    if(specialKeys[{signatureKey,key}] == SpecialKey::BACKSPACE)
    {
        if(cursorPosition.second != 0)
        {
            cursorPosition.second--;
        }
        else
        {
            if(cursorPosition.first != 0)
            {
                cursorPosition.first--;
            }
        }
        return SpecialKey::BACKSPACE;
    }
    return SpecialKey::NONE;
}

OutputKeyHandler::OutputKeyHandler() {}
