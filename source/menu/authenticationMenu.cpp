#include "authenticationMenu.hpp"
#include "mainMenu.hpp"

void LoginMenu::init() {
    menuName = "LOGIN";
    submenus = {{"",new MainMenu()}};
    MenuRepository::menus[menuName] = this;
    
    std::vector<std::string> inputs = {"identifier", "password"};
    std::vector<std::string> inputLabels = {
        "(i) Username, Email or Phone number: ",
        "(i) Password: ",
    };
    if(fillForm({}, inputLabels,  inputs) == TerminationCode::QUIT) return;
    localUserApi.login(inputs[0], inputs[1]);
}
void SignUpMenu::init() {
    menuName = "SIGN UP";
    submenus = {{"",new MainMenu()}};
    MenuRepository::menus[menuName] = this;

    std::vector<std::string> inputs = {"username", "password", "repeatedPassword", "email", "phoneNumber"};
    std::vector<std::string> inputLabels = {
        "(i) Username: ",
        "(i) Password: ",
        "(i) Repeat password: ",
        "(i) Email: ",
        "(i) Phone number (optional): "
    };
    if(fillForm({}, inputLabels, inputs) == TerminationCode::QUIT) return;
    localUserApi.signUp(inputs[0], inputs[1], inputs[2]);
}
void AuthenticationMenu::init() {
    menuName = "AUTHENTICATION";
    submenus = {{"1", new LoginMenu()}, {"2", new SignUpMenu()}};
    MenuRepository::menus[menuName] = this;

    std::string output = 
        "1. Login \n"
        "2. Register \n";

    chooseSubmenu(output);
}
void VerifyEmailMenu::init() {}

