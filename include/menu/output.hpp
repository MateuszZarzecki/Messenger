#pragma once
#include <iostream>
#include <sstream>

#include "projectBase.hpp"

enum class ConsoleCode {
    NLINE,
    DEL_PREV_CHAR,DEL_LINE,CLEAR_PAGE,
    TX_WHITE,TX_BLACK,TX_GREEN,TX_RED,TX_BLUE,
    BG_WHITE,BG_BLACK,BG_GREEN,BG_RED,BG_BLUE
};

class ConsoleOutput {
protected:
    std::ostream& consoleCodeHandling(std::ostream& os, ConsoleCode consoleCode);
};

class OutputString : public ConsoleOutput {
public:
    OutputString() = default;

    S stream();

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
        return *this;
    }
    template<typename OutputType>
    OutputHandler& operator<<(OutputType& output) {
        os << output;
        return *this;
    }
    OutputHandler& operator<<(ConsoleCode consoleCode);
    OutputHandler& operator<<(OutputString& consoleString);

    void clearOutputBuffer();
    S getOutputBuffer();
private:
    S outputs;
    std::ostream& os;
};
