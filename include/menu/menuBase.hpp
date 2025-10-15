#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>

#include "projectBase.hpp"
#include "input.hpp"
#include "consoleUtils.hpp"

class MenuBase {
public:   
    virtual void init() = 0;
protected:
    Console console;
    InputHandler inputHandler;

    std::string menuName;
    std::unordered_map<std::string,MenuBase*> submenus;

    TerminationCode chooseSubmenu(std::string output);
    TerminationCode fillForm(std::vector<std::string> outputs, std::vector<std::string> inputLabels, std::vector<std::string>& inputs);
    void wrongInput();
};
class MenuDisplay {
public:
    void display();
    void clear();

    void addHeader(std::string menuName);
    void addContent(std::string newContent);
    void addFooter();
private:
    Console console;
    std::string header, content, footer;
};

namespace MenuRepository {
    inline MenuBase* current;
    inline std::unordered_map<std::string, MenuBase*> menus;
    inline std::vector<std::string> previous;
    inline MenuDisplay menuDisplay;
};



