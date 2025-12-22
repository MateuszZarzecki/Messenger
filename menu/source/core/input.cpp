#include "input.hpp"

const bool InputKeyHandler::SIGNATURE = true;

P<C,SpecialKey> InputKeyHandler::handleKey(I key)
{
    P<C,SpecialKey> result;

    P<I,I> printableKeysRange = {32,126};
    V<I> specialPrintableKeys = {58};

    if(printableKeysRange.first <= key && key <= printableKeysRange.second)
    {
        for(I specialKey : specialPrintableKeys)
        {
            if(key == specialKey)
            {
                result.first = (C)key;
                break;
            }
        }
    }
    SpecialKey specialKey = handleSpecialKey(key);
    result.second = specialKey;

    return result;
}
SpecialKey InputKeyHandler::handleSpecialKey(int key)
{
    P<I,I> extendedKeysSignatures = {0,224};

    M<P<B,I>,SpecialKey> specialKeys = {
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


InputHandler::InputHandler()
    : inputs({{}}), inputKeyHandler(inputs,cursorPosition) {}

Return<MenuOutcome,P<C,SpecialKey>> InputHandler::processInput()
{
    Return<MenuOutcome,P<C,SpecialKey>> result = {MenuOutcome::NONE,{'\0',SpecialKey::NONE}};

    int key = getch();
    P<C,SpecialKey> processedKey = inputKeyHandler.handleKey(key);
    result.data.second = processedKey.second;

    //IN KEYHANDLER
    if(processedKey.first != '\0')
    {
        C character = processedKey.first;
        S& currentInput = inputs[inputs.size()-1][inputs[inputs.size()-1].size()-1];

        currentInput += character;
        //COMMANDHANDLER GETS DYNAMIC INPUT SO I KNOW WHEN COMMAND HAS STARTED EASIER HANDLER IMPLEMENTATION
        currentInput = commandHandler.unescapePrefixes(currentInput);
        result.outcome = commandHandler.handleCommands(currentInput);
        result.data.first = character;
    }
    //EFFECT
    if(result.outcome == MenuOutcome::FINISH)
    {
        inputs[inputs.size()-1].push_back({});
    }
    return result;
}

void InputHandler::setEffects(V<P<std::function<void(S&)>,I>> effects)
{
    this->effects = effects;
}
void InputHandler::clearEffects()
{
    effects.clear();
}

void InputHandler::setMultilineInput(B isMultiline)
{
    multiline = isMultiline;
}

void InputHandler::newInputPage()
{
    inputs.push_back({{}});
}

V<V<S>> InputHandler::getInputs()
{
    return inputs;
}
void InputHandler::setInputs(V<V<S>> inputs)
{
    this->inputs = inputs;
}
