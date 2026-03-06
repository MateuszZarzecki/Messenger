#pragma once

#include "projectBase.hpp"

enum class SpecialKey
{
    NONE=-1,
    BACKSPACE,COLON,SEMICOLON,TAB,ENTER,DELETE,
    ARROW_LEFT,ARROW_TOP,ARROW_RIGHT,ARROW_DOWN,
    LINE_HOME,LINE_END,MULTILINE_HOME,MULTILINE_END,
    PAGE_UP_CURSOR,PAGE_DOWN_CURSOR,PAGE_UP_VIEW,PAGE_DOWN_VIEW
};

enum class KeyPrefix
{
    YES,NO
};

class InputKeyResolver
{
public:

    InputKeyResolver();
    Pair<char,SpecialKey> resolveKey(int key);
private:
    Map<Pair<KeyPrefix,int>,SpecialKey> specialKeys;
    bool keyPrefix;

    SpecialKey resolveSpecialKey(int specialKey);
};
