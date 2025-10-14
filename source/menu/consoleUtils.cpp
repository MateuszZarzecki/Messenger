#include "consoleUtils.hpp"

Console::Console()
: sink(std::cout), locked(false) {}

Console::Console(std::ostream& os)
: sink(os), printableChars(32,126), locked(false) {}

char Console::getChar() {
    char character;
    do {
        character = std::cin.get();
    } while(!(printableChars.first <= character && character <= printableChars.second));
    return character;
}
Console& Console::operator<<(std::ostream& (*manip)(std::ostream&)) {
    buffer << manip;
    flush();
    return *this;
}
Console& Console::operator<<(ConsoleCode consoleCode) {
    switch(consoleCode) {
        case ConsoleCode::NLINE:
            buffer << std::endl;
            break;
        case ConsoleCode::LOCK:
            locked = true;
            break;
        case ConsoleCode::UNLOCK:
            locked = false;
            break;
        default: break;
        //REST CODES
    }
    flush();
    return *this;
}

void Console::flush() {
    if(!locked) {
        sink << buffer.str();
        buffer.str("");
    }
}
