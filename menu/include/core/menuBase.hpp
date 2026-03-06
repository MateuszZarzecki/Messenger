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

class UIElement
{
public:
    enum class State {NONE,FOCUSED,SUCCEED,INFO,WARNING,ERROR};
    virtual OutputString& display() = 0;

    void setState(State state);
    State getState();
protected:
    OutputString oString;
    State state;
};

class InteractiveUIElement : public UIElement
{
public:
    OutputString& display() override = 0;

    void addEffect(std::function<void()> effect);
    void clearEffects();
private:
    Vector <std::function<void()>> effects;
};

class UILayout : public UIElement
{
public:
    void addElement();
    void clearElements();
private:
    Vector <UIElement*> elements;
};

//=====STATIC UI ELEMENTS=====//

class UILabel : public UIElement
{
public:
    UILabel(String label);
    OutputString& display() override;

    void setLabel(String label);
    String getLabel();
private:
    String label;
};
class UIHeader : public UIElement
{
public:
    UIHeader(String menuName);
    OutputString& display() override;

    void setMenuName(String menuName);
    String getMenuName();
private:
    String menuName;
};
//=====INTERACTIVE UI ELEMENTS=====//

class UICommandInput : public InteractiveUIElement
{
private:
    bool active;
};

class UITextInput : public InteractiveUIElement
{
public:
    UITextInput(String shadowText);
    OutputString& display() override;
};
class UICheckbox : public InteractiveUIElement
{
public:
    UICheckbox(bool checked);
    OutputString& display() override;
};
class UIProgressBar : public InteractiveUIElement
{
public:
    UIProgressBar(int progress);
    OutputString& display() override;
};

//=====UI CONTAINTERS=====//

class UIHorizontalLayout : public UILayout
{
};
class UIVerticalLayout : public UILayout
{
};
class UIMenuLayout : public UILayout
{
    String getMenuName();
private:
    const String menuName;
};
class Frame : public UIVerticalLayout
{
public:
    Frame(UIMenuLayout menu);

    UIHeader header;
    UIMenuLayout* menuLayout;
    UICommandInput* commandInput;
};




















