#include "authenticationMenu.hpp"
#include "mainMenu.hpp"

TerminationCode globalTermiantionCode = TerminationCode::NONE;

void AuthenticationMenu::display()
{
    menuName = "AUTHENTICATION";
    submenus = {{"1", new LoginMenu()}, {"2", new SignUpMenu()}};

    std::string output =
        "1. Login \n"
        "2. Register \n";

    if(chooseSubmenu(output) == TerminationCode::QUIT) return;
}
void LoginMenu::display()
{
    menuName = "LOGIN";
    submenus = {{"",new MainMenu()}};

    std::vector<std::string> inputs = {"identifier", "password"};
    std::vector<std::string> outputs = {
        "(i) Username, Email or Phone number: ",
        "(i) Password: ",
    };
    if(fillForm(outputs, inputs) == TerminationCode::QUIT) return;
    localUserApi.login(inputs[0], inputs[1]);
}
void SignUpMenu::display()
{
    menuName = "SIGN UP";
    submenus = {{"",new VerifyEmailMenu()}};

    std::vector<std::string> inputs = {"username", "password", "repeatedPassword", "email", "phoneNumber"};
    std::vector<std::string> outputs = {
        "(i) Username: ",
        "(i) Password: ",
        "(i) Repeat password: ",
        "(i) Email: ",
        "(i) Phone number (optional): "
    };
    if(fillForm(outputs, inputs) == TerminationCode::QUIT) return;
    localUserApi.signUp(inputs[0], inputs[1], inputs[2]);
}
void VerifyEmailMenu::display()
{
    menuName = "VERIFY EMAIL";
    submenus = {{"",new MainMenu()}};

    std::string output =
        "We sent you verification link on \"" + SocialNetworkRepository::;
}



