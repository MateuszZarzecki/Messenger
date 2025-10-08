#include <iostream>

#include "menuBase.hpp"
#include "input.hpp"
#include "consoleUtils.hpp"

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

    //---FOURTH TEST
    Console console(std::cout);
    console << "anc";
    return 0;
}
