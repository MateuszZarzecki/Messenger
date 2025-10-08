#include "consoleUtils.hpp"


Console::Console(std::ostream& os)
    : os(os), printableChars(32,126) {}

char Console::getChar() {
    char character;
    do {
        character = std::cin.get();
    } while(!(printableChars.first <= character && character <= printableChars.second));
    return character;
}
Console& Console::operator<<(ConsoleCode consoleCode) {
    switch(consoleCode) {
        case ConsoleCode::NLINE:
            os << std::endl;
            break;
        //REST CODES
    }
    return *this;
}
