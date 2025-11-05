#include "authenticationMenu.hpp"
#include "mainMenu.hpp"

void AuthenticationMenu::display()
{
    menuName = "AUTHENTICATION";
    submenus = {{"1", new LoginMenu()}, {"2", new SignUpMenu()}};

    V<P<S,S>> output =
    {
        {"1. ", "Login"},
        {"2. ", "Register"}
    };
    if(chooseSubmenu(output) == TerminationCode::QUIT) return;
}
void LoginMenu::display()
{
    menuName = "LOGIN";
    submenus = {{"",new MainMenu()}};

    V<S> inputs = {"identifier", "password"};
    V<S> outputs = {
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

    V<S> inputs = {"username", "password", "repeatedPassword", "email", "phoneNumber"};
    V<S> outputs = {
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

    V<P<S,S>> output =
    {
        //{"Click a link sent on \"" + primeUser->email + "\"\n\n"},
        {"1. ","Back"},
        {"2. ","Info"},
    };
}



