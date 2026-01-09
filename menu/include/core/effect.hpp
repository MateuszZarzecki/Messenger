#pragma once

#include <iostream>
#include <functional>

#include "projectBase.hpp"

class Interaction;

class EffectsHandler
{
public:
    EffectsHandler();

    void newPage(V<Interaction>& interactions);
    void setEffects(V<std::function<void(V<Interaction>&)>> effects);
    void handleEffects();
private:
    V<Interaction>& interactions;
    V<std::function<void(V<Interaction>&)>> effects;
};


*    Imie; |
*    Nazwisko |
*    Password |
    |
