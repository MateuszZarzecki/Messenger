#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include <stack>

#include "projectBase.hpp"
#include "output.hpp"
#include "input.hpp"


//=====UI BASE CLASSES =====//
class UILayout;

class UIElement
{
public:
    virtual OutputString& display() = 0;
protected:
    OutputString oString;
};
class UIInteractiveElement : public UIElement
{
public:
    OutputString& display() override = 0;

    virtual bool handleInput(Pair<char,SpecialKey> input) = 0;

    void addEffect();
    void remoteEffect(int index);
    void clearEffects();

    UILayout* parentLayout;
private:
    Vector <std::function<void()>> effects;
};

class UILayout : public UIElement
{
public:
    OutputString& display() override = 0;

    virtual bool handleMovement(Pair<char,SpecialKey> input, UIInteractiveElement* focused) = 0;

    void addElement(UIElement* element);

    void removeElement(int index);
    void removeElement(UIElement* elementPointer);
    void clearElements();

    UILayout* parentLayout;
private:
    Vector <UIElement*> elements;
};

//=====STATIC UI ELEMENTS=====//

class UILabel : public UIElement
{
public:
    UILabel(String label);
    OutputString& display() override;

    String label;
};
class UIHeader : public UIElement
{
public:
    UIHeader(String menuName);
    OutputString& display() override;

    String menuName;
};
//=====INTERACTIVE UI ELEMENTS=====//

class UITextInput : public UIInteractiveElement
{
public:
    UITextInput(String shadowText);
    OutputString& display() override;

    String shadowText;
    String input;
};
class UICommandInput : public UITextInput
{
    UICommandInput(bool active);
    OutputString& display() override;

    bool active;
};

class UICheckbox : public UIInteractiveElement
{
public:
    UICheckbox(bool checked);
    OutputString& display() override;

    bool checked;
};
class UIProgressBar : public UIInteractiveElement
{
public:
    UIProgressBar(int progress);
    OutputString& display() override;

    int progress;
};

//=====UI CONTAINTERS=====//

class UIHorizontalLayout : public UILayout
{
public:
    OutputString& display() override;
};
class UIVerticalLayout : public UILayout
{
public:
    OutputString& display() override;
};

//===== SUPERIOR UI CONTAINTERS=====//

class UIMenuLayout : public UILayout
{
public:
    OutputString& display() override;

    String menuName;
    UnorderedMap<String,UIMenuLayout*> submenus;
};
class Frame : public UIVerticalLayout
{
public:
    OutputString& display() override;

    UIMenuLayout* menuLayout;
    UIInteractiveElement* focused;
};
