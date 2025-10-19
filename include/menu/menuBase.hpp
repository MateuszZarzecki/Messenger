#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>

#include "projectBase.hpp"
#include "input.hpp"
#include "consoleUtils.hpp"
#include "stack"

class Content {

};
class InputContent : public Content {

};
class OutputContent : public Content {

};

class MenuDisplay {
public:
    void clear();

    void addHeader(std::string menuName);
    void addContent(std::vector<Content> content);
private:
    Console console;
    std::string header, content, inputs;
};

class MenuBase {
public:   
    virtual void init() = 0;
protected:
    Console console;
    MenuDisplay menuDisplay;
    InputHandler inputHandler;

    std::string menuName;
    std::unordered_map<std::string,MenuBase*> submenus;

    TerminationCode chooseSubmenu(std::string output);
    TerminationCode fillForm(std::vector<std::string> outputs, std::vector<std::string> inputLabels, std::vector<std::string>& inputs);
    void wrongInput();
};

namespace MenuRepository {
    inline MenuBase* current = nullptr;
    inline std::stack<MenuBase*> previousMenus = {};
};



