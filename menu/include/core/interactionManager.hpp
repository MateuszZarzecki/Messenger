#pragma once
#include <functional>

#include "effect.hpp"
#include "input.hpp"
#include "output.hpp"
#include "projectBase.hpp"

class Interaction
{
public:
    Interaction(S prompt, V<S> input, S& interaction);

    S getPrompt();
    void setPrompt();

    V<S> getInput();
    void setInput();

    S getInteractionPayload();
    void setInteractionPayload();
private:
    S prompt;
    size_t promptStartLine, promptEndLine, promptStartInLinePosition, promptEndInLinePosition;

    V<S> input;
    size_t inputStartLine, inputEndLine, inputStartInLinePosition, inputEndInLinePosition;

    S& interactionPayload;
};

class InteractionManager
{
public:
    InteractionManager(MenuRepository& menuRepository);
    Return<MenuOutcome,V<S>> handlePageInteraction(V<P<S,B>> prompts, B newPage);

    V<Interaction> getInteractions();
    Interaction getInteraction(size_t position);

    V<Interaction> interactions; // to w private

private:
    OutputHandler outputHandler;
    InputHandler inputHandler;
    EffectsHandler effectsHandler;

    //interact(P<S,B> prompt)
};
