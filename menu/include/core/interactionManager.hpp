#pragma once
#include <functional>


#include "input.hpp"
#include "output.hpp"
#include "projectBase.hpp"

class InteractionManager
{
public:
    InteractionManager(MenuRepository& menuRepository);
    //ADD EFFECTS
    Return<MenuOutcome,V<S>> interact(V<P<S,B>> prompts, B newPage);
private:
    OutputHandler outputHandler;
    InputHandler inputHandler;
};
