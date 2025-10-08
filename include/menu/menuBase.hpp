#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>

#include "projectBase.hpp"
#include "input.hpp"

struct MenuRepository;

class MenuBase {
public:   
    static void setMenuRepository(MenuRepository* menuRepository);
    virtual void init() = 0;
protected:
    static MenuRepository* menuRepository;
    InputHandler inputHandler;  

    std::string menuName;
    std::unordered_map<std::string,MenuBase*> submenus;

    TerminationCode chooseSubmenu(std::string output);
    TerminationCode fillForm(std::vector<std::string> outputs, std::vector<std::string> inputs);
    void wrongInput();
};
class MenuDisplay {
public:
    void display();
    void clear();

    void addHeader(std::string menuName);
    void addContent(std::string content);
    void addFooter();
private:
    Console console;
    std::string header, content, footer;
};
struct MenuRepository {
    MenuRepository();

    MenuBase* current;
    std::unordered_map<MenuBase*,std::string> menus;
    std::vector<std::string> previous;
    MenuDisplay menuDisplay;
};

