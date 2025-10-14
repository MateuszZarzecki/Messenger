#include "authenticationMenu.hpp"
#include "mainMenu.hpp"

void LoginMenu::init() {
    menuName = "LOGIN";
    submenus = {{"",new MainMenu()}};
    //MenuRepository::menus[this] = menuName;
    
    std::vector<std::string> inputs = {"identifier", "password"};
    std::vector<std::string> outputs = {
        "username, email or phone number: ",
        "password: ",            
    };
    if(fillForm(outputs, inputs) == TerminationCode::QUIT) return;
    //localUserApi.login(inputs[0], inputs[1]);
}
void SignUpMenu::init() {
    menuName = "SIGN UP";
    submenus = {{"",new MainMenu()}};
    //MenuRepository::menus[this] = menuName;

    std::vector<std::string> inputs = {"username", "password", "repeatedPassword", "email", "phoneNumber"};
    std::vector<std::string> outputs = {
        "username: ",
        "password: ",
        "repeat password: ",
        "email: ",
        "phone number (optional): "
    };
    if(fillForm(outputs, inputs) == TerminationCode::QUIT) return;
    //localUserApi.signUp(inputs[0], inputs[1], inputs[2]);
}
void AuthenticationMenu::init() {
    menuName = "AUTHENTICATION";
    submenus = {{"1", new LoginMenu()}, {"2", new SignUpMenu()}};
    //MenuRepository::menus[this] = menuName;

    std::string output = 
        "Welcome in " + ApplicationData::projectName + 
        "\n------------ \n"
        "1. Login \n"
        "2. Register \n";
    chooseSubmenu(output);
}
void VerifyEmailMenu::init() {}
