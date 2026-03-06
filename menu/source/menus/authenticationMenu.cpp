#include "authenticationMenu.hpp"

OutputString& AuthenticationMenu::display()
{
    menuName = "AUTHENTICATION";
    submenus = {{"1", new LoginMenu()}, {"2", new SignUpMenu()}};

    String output = "1. Login\n"
                    "2. Register\n";

    chooseSubmenu(output);
}
// void LoginMenu::display()
// {
//     menuName = "LOGIN";
//     submenus = {{"",new MainMenu()}};

//     V<S> inputs = {"identifier", "password"};
//     V<P<S,B>> outputs =
//     {
//         {"(i) Username, Email or Phone number: ",false},
//         {"(i) Password: ",false}
//     };
//     if(fillForm(outputs).outcome != MenuOutcome::NONE) return;
//     //localUserApi.login(inputs[0], inputs[1]);
// }
// void SignUpMenu::display()
// {
//     menuName = "SIGN UP";
//     submenus = {{"",new VerifyEmailMenu()}};

//     V<S> inputs = {"username", "password", "repeatedPassword", "email", "phoneNumber"};
//     V<P<S,B>> outputs =
//     {
//         {"(i) Username: ",false},
//         {"(i) Password: ",false},
//         {"(i) Repeat password: ",false},
//         {"(i) Email: ",false},
//         {"(i) Phone number (optional): ",false}
//     };
//     if(fillForm(outputs).outcome != MenuOutcome::NONE) return;
//     localUserApi.signUp(inputs[0], inputs[1], inputs[2]);
// }
// void VerifyEmailMenu::display()
// {
//     menuName = "VERIFY EMAIL";
//     submenus = {{"",new MainMenu()}};

//     S output = "Enter 4-digit code sent on " + primeUser->email + ":\n"
//                 "____";
// }



