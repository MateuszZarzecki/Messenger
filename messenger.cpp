#include <iostream>
#include "output.hpp"
#include "menuManager.hpp"
#include "localUserApi.hpp"

#include <sstream>

#include <limits>

int main() {
    OutputHandler outputHandler;
    InputHandler inputHandler;
    InteractionManager interactionManager;

    while(true)
    {
        int c = getch();
        std::cout << c << std::endl;
    }
}
