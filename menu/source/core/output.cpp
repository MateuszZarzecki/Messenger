#include "output.hpp"

std::ostream& ConsoleOutput::consoleCodeHandling(std::ostream& os, ConsoleCode consoleCode)
{
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

S OutputString::getString()
{
    return oss.str();
}

OutputString& OutputString::operator<<(OutputString& consoleString)
{
    oss << consoleString.getString();
    return *this;
}

OutputString& OutputString::operator<<(ConsoleCode consoleCode)
{
    consoleCodeHandling(oss, consoleCode);
    return *this;
}

OutputHandler::OutputHandler() : os(std::cout) {}

OutputHandler& OutputHandler::operator<<(OutputString& consoleString)
{
    os << consoleString.getString();
    return *this;
}
OutputHandler& OutputHandler::operator<<(ConsoleCode consoleCode)
{
    consoleCodeHandling(os, consoleCode);
    return *this;
}
void OutputHandler::clearOutputBuffer()
{
    outputs.clear();
}
V<S> OutputHandler::getOutputBuffer()
{
    return outputs;
}
