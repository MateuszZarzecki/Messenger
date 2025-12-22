#include "interactionManager.hpp"

//ADD EFFECTS
Return<MenuOutcome,V<S>> InteractionManager::interact(V<P<S,B>> prompts, B newPage)
{
    Return<MenuOutcome,V<S>> inputs;

    if(newPage)
    {
        outputHandler << ConsoleCode::CLEAR_PAGE;
    }

    inputHandler.newInputPage();
    for(const P<S,B> &singlePrompt : prompts)
    {
        S output = singlePrompt.first;
        B inputMultiline = singlePrompt.second;

        outputHandler << output;

        inputHandler.setMultilineInput(inputMultiline);
        while(true)
        {
            Return<MenuOutcome,P<C,SpecialKey>> processedKey = inputHandler.processInput();
            inputs.outcome = processedKey.outcome;

            outputHandler.handleSpecialKeys(processedKey.data.second);
            if(processedKey.data.first != '\0')
            {
                C character = processedKey.data.first;
                outputHandler << character;
            }


            if(inputs.outcome == MenuOutcome::QUIT) return inputs;
            if(inputs.outcome == MenuOutcome::FINISH)
            {
                break;
            }
        }
    }
    inputs.data = inputHandler.getInputs()[inputHandler.getInputs().size()-1];
    return inputs;
}
