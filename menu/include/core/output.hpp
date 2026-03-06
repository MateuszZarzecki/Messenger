#pragma once
#include <iostream>
#include <sstream>
#include <functional>

#include "projectBase.hpp"
#include "key.hpp"
#include "command.hpp"

enum class ConsoleCode {
    NLINE,
    DEL_PREV_CHAR,DEL_LINE,CLEAR_PAGE,
    TX_WHITE,TX_BLACK,TX_GREEN,TX_RED,TX_BLUE,
    BG_WHITE,BG_BLACK,BG_GREEN,BG_RED,BG_BLUE
};

class ConsoleOutput {
protected:
    std::ostream& handleConsoleCode(std::ostream& os, ConsoleCode consoleCode);
};

class OutputString : public ConsoleOutput {
public:
    String getString();

    template<typename OutputType>
    OutputString& operator<<(OutputType&& output) {
        oss << output;
        return *this;
    }
    template<typename OutputType>
    OutputString& operator<<(OutputType& output){
        oss << output;
        return *this;
    }
    OutputString& operator<<(ConsoleCode consoleCode);
    OutputString& operator<<(OutputString& consoleString);
private:
    std::ostringstream oss;
};

class OutputHandler : public ConsoleOutput {
public:
    OutputHandler();

    template<typename OutputType>
    OutputHandler& operator<<(OutputType&& output) {
        os << output;
        updateOutputStore(output);
        return *this;
    }
    template<typename OutputType>
    OutputHandler& operator<<(OutputType& output) {
        os << output;
        updateOutputStore(output);
        return *this;
    }
    OutputHandler& operator<<(ConsoleCode consoleCode);
    OutputHandler& operator<<(OutputString& outputString);

private:
    std::ostream& os;
    std::ostringstream oss;
};


































































