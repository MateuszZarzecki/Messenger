#include <iostream>

#include "authenticationMenu.hpp"
#include "menuBase.hpp"
#include "input.hpp"
#include "consoleUtils.hpp"
#include "menuManager.hpp"
#include "localUserApi.hpp"

#include <limits>


int main() {
    int i;
    std::cout << "\nHello\n";

    //---FIRST TEST - PASSED
    // MenuDisplay menuDisplay;
    // menuDisplay.addHeader("AUTHENTICATION");
    // menuDisplay.addContent("Content of menu");
    // menuDisplay.display();

    //---SECOND TEST - PASSED
    // InputHandler inputHandler;
    // Console console;

    // char character;
    // console.getChar(character);
    // std::cout << character;

    //---THIRD TEST - PASSED
    // InputHandler inputHandler;
    // inputHandler.getInput();

    //---FOURTH TEST - PASSED
    // Console console(std::cout);
    // console << "anc";

    //---FIFTH TEST --- PASSED
    // Console console(std::cout);
    // char c = console.getChar();
    // console << c << std::endl << c;

    //---SIXTH TEST ---PASSED
    // AuthenticationMenu auth;
    // auth.init();

    //---SEVENTH TEST ---PASSED
    // MenuManager menuManager;
    // menuManager.display();

    //---EIGHTH TEST --- FAILED
    // LocalUserAPI local;
    // local.login("mateusz123!@#", "mati");

    // try
    // {
    //     http::Request request{"http://130.162.35.167:1880/messenger/api/user/login"};
    //     json bodyJson = json({{"serverConn", {{"username", "mateusz123!@#"}, {"password", "mati"}}}});
    //     std::cout << bodyJson.dump() << std::endl;
    //     const std::string body = "{\"serverConn\":{\"username\":\"mateusz123!@#\",\"password\":\"mati\"}}";
    //     const auto response = request.send("POST", bodyJson.dump(), {
    //                                                          {"Content-Type", "application/json"}
    //                                                      });
    //     std::cout << body << std::endl;
    //     std::cout << std::string{response.body.begin(), response.body.end()} << '\n'; // print the result
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << "Request failed, error: " << e.what() << '\n';
    // }
    // LocalUserAPI local;
    // local.login("mateusz123!@#", "mati");
    MenuManager menuManager;
    menuManager.display();
    return 0;
}
