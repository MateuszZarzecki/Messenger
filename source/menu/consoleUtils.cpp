#include "consoleUtils.hpp"

char ConsoleUtility::getChar() {
    return std::cin.get();
}

std::ostream& ConsoleBase::consoleCodeHandling(std::ostream& os, ConsoleCode consoleCode) {
    switch(consoleCode) {
    case ConsoleCode::NLINE:
        os << std::endl;
        break;
    case ConsoleCode::CLEAR_PAGE:
        os << "\033[2J\033[1;1H";
        break;
    default:
        break;
    }
    return os;
}

ConsoleString& ConsoleString::operator<<(ConsoleString& consoleString) {
    oss << consoleString.stream();
    return *this;
}

ConsoleString& ConsoleString::operator<<(ConsoleCode consoleCode) {
    consoleCodeHandling(oss, consoleCode);
    return *this;
}

Console::Console() : os(std::cout) {}

Console& Console::operator<<(ConsoleString& consoleString) {
    os << consoleString.stream();
    return *this;
}

Console& Console::operator<<(ConsoleCode consoleCode) {
    consoleCodeHandling(os, consoleCode);
    return *this;
}
