#pragma once

#include <iostream>
#include <functional>

#include "projectBase.hpp"

template <typename DataType>
class EffectsHandler
{
public:
    EffectsHandler() = default;

    void setData(DataType* data)
    {
        this->data = data;
    }

    void setEffects(V<std::function<void(DataType&)>> effects)
    {
        this->effects = effects;
    }
    void clearEffects()
    {
        effects.clear();
    }
    void handleEffects()
    {
        for(std::function<void(DataType&)> effect : effects)
        {
            effect(*data);
        }
    }
private:
    DataType* data;
    V<std::function<void(DataType&)>> effects;
};

class InteractionEffectsHandler
{
public:
    InteractionEffectsHandler();

    void setInteractionEffects(V<P<std::function<void(V<S>&)>,std::function<void(S&)>>> interactionEffects);
private:
    EffectsHandler<S> outputEffectsHandler;
    EffectsHandler<V<S>> inputEffectsHandler;
};
