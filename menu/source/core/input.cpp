#include "input.hpp"

InputHandler::InputHandler(MenuRepository& menuRepository)
    : inputs({{}}), inputKeyHandler(inputs,cursorPosition), commandHandler(menuRepository) {}

Return<MenuOutcome,P<C,SpecialKey>> InputHandler::processInput()
{
    Return<MenuOutcome,P<C,SpecialKey>> result = {MenuOutcome::NONE,{'\0',SpecialKey::NONE}};

    int key = getch();
    P<C,SpecialKey> processedKey = inputKeyHandler.handleKey(key);
    MenuOutcome outcome = commandHandler.handleCommands(inputs.back().back());
    if(outcome == MenuOutcome::NONE || outcome == MenuOutcome::FINISH)
    {
        //interactionEffectsHandler();
    }

    result.outcome = outcome;
    result.data = processedKey;
    return result;
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
