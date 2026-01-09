#include "interactionManager.hpp"

InteractionManager::InteractionManager(MenuRepository& menuRepository)
    : inputHandler(menuRepository) {}

Return<MenuOutcome,V<S>> InteractionManager::handlePageInteraction(V<P<S,B>> prompts, B newPage)
{
    Return<MenuOutcome,V<S>> result;

    if(newPage)
    {
        interactions.clear();

        inputHandler.newPage();
        outputHandler.newPage();
        effectsHandler.newPage(interactions);
    }
    for(const P<S,B> &singlePrompt : prompts)
    {
        S output = singlePrompt.first;
        B inputMultiline = singlePrompt.second;

        outputHandler.newInteraction();
        outputHandler << output;
        interactions.push_back(output,"",outputHandler.get);

        inputHandler.setMultilineInput(inputMultiline);
        while(true)
        {
            Return<MenuOutcome,P<C,SpecialKey>> processedKey = inputHandler.processInput();
            result.outcome = processedKey.outcome;
            outputHandler.handleKey(processedKey.data);

            if(result.outcome == MenuOutcome::NONE || result.outcome == MenuOutcome::FINISH)
            {
                effectsHandler.handleEffects();
            }
            if(result.outcome == MenuOutcome::QUIT) return result;
            if(result.outcome == MenuOutcome::FINISH) break;
        }
    }
    result.data = inputHandler.getInputs().back();
    return result;
}
