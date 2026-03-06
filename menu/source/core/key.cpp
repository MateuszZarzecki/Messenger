#include "key.hpp"


InputKeyResolver::InputKeyResolver()
    : keyPrefix(false)
{
    specialKeys =
    {
        {{KeyPrefix::NO,8},SpecialKey::BACKSPACE},
        {{KeyPrefix::NO,9},SpecialKey::TAB},
        {{KeyPrefix::NO,13},SpecialKey::ENTER},

        {{KeyPrefix::YES,83},SpecialKey::DELETE},
        {{KeyPrefix::YES,75},SpecialKey::ARROW_LEFT},
        {{KeyPrefix::YES,72},SpecialKey::ARROW_TOP},
        {{KeyPrefix::YES,77},SpecialKey::ARROW_RIGHT},
        {{KeyPrefix::YES,80},SpecialKey::ARROW_DOWN},
        {{KeyPrefix::YES,71},SpecialKey::LINE_HOME},
        {{KeyPrefix::YES,79},SpecialKey::LINE_END},
        {{KeyPrefix::YES,119},SpecialKey::MULTILINE_HOME},
        {{KeyPrefix::YES,117},SpecialKey::MULTILINE_END},
        {{KeyPrefix::YES,73},SpecialKey::PAGE_UP_CURSOR},
        {{KeyPrefix::YES,81},SpecialKey::PAGE_DOWN_CURSOR},
        {{KeyPrefix::YES,134},SpecialKey::PAGE_UP_VIEW},
        {{KeyPrefix::YES,118},SpecialKey::PAGE_DOWN_VIEW},
    };
}

Pair <char,SpecialKey> InputKeyResolver::resolveKey(int key)
{
    Pair <char,SpecialKey> result = {-1,SpecialKey::NONE};

    Scope<int> printableKeysRange = {32,126};
    Vector <Pair<int,SpecialKey>> specialPrintableKeys = {{58,SpecialKey::COLON}};

    if(printableKeysRange.in(key))
    {
        result.first = (char)key;
        for(Pair <int,SpecialKey> specialKey : specialPrintableKeys)
        {
            if(key == specialKey.first)
            {
                result.second = specialKey.second;
                break;
            }
        }
    }
    else
    {
        SpecialKey specialKey = resolveSpecialKey(key);
        result.second = specialKey;
    }
    return result;
}
SpecialKey InputKeyResolver::resolveSpecialKey(int key)
{
    int constexpr specialKeySignature_1 = 0;
    int constexpr specialKeySignature_2 = 224;

    if(key == specialKeySignature_1 || key == specialKeySignature_2)
    {
        keyPrefix = true;
    }
    else
    {
        if(keyPrefix)
        {
            keyPrefix = false;
            if(specialKeys.find({KeyPrefix::YES,key}) != specialKeys.end())
            {
                return specialKeys[{KeyPrefix::YES,key}];
            }
        }
        else
        {
            if(specialKeys.find({KeyPrefix::NO,key}) != specialKeys.end())
            {
                return specialKeys[{KeyPrefix::NO,key}];
            }
        }
    }
    return SpecialKey::NONE;
}
