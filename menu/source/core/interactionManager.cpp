#include "interactionManager.hpp"

//ADD EFFECTS
Return<MenuOutcome,V<S>> InteractionManager::interact(V<P<S,B>> prompts, B newPage)
{
    Return<MenuOutcome,V<S>> result;

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
            result.outcome = processedKey.outcome;
            outputHandler.handleKey(processedKey.data);

            if(result.outcome == MenuOutcome::QUIT) return result;
            if(result.outcome == MenuOutcome::FINISH) break;
        }
    }
    result.data = inputHandler.getInputs().back();
    return result;
}
