#include "input.hpp"
#include "consoleUtils.hpp"
#include "signal.hpp"

MenuRepository* InputHandler::menuRepository = nullptr;

void InputHandler::setMenuRepository(MenuRepository* menuRepository) {
    InputHandler::menuRepository = menuRepository;
    SignalHandler::setMenuRepository(menuRepository);
}
std::pair<std::string,TerminationCode> InputHandler::getInput(bool multiLine){
    std::string message = "";
    std::string inputLine = "";
    char character;
    do {
        while(true) {
            {
                character = std::cin.get();
                inputLine += character;
                message += inputLine;

                if(character == '\n') {
                    std::cout << "endl";
                    return {message, TerminationCode::NONE};
                }
                // signalHandler.handleSignals(message);
                // signalHandler.unescapePrefixes(message);
            } 
        } 
        message += "\n";
    } while(multiLine);
    return {};
}    
