#include "effect.hpp"

void EffectsHandler::newPage(V<Interaction>& interactions)
{
    effects.clear();
    this->interactions = interactions;
}
void EffectsHandler::setEffects(V<std::function<void(V<Interaction>&)>> effects)
{
    this->effects = effects;
}
void EffectsHandler::handleEffects()
{
    for(size_t i=0;i<effects.size();i++)
    {
        (this->effects[i])(interactions);
    }
}
