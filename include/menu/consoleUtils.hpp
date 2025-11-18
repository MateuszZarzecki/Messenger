//STATIC set methods ??? are they nessecary

#pragma once
#include <iostream>
#include <sstream>
#include <conio.h>

enum class ConsoleCode {
    NLINE,
    DEL_PREV_CHAR,DEL_LINE,CLEAR_PAGE,
    TX_WHITE,TX_BLACK,TX_GREEN,TX_RED,TX_BLUE,
    BG_WHITE,BG_BLACK,BG_GREEN,BG_RED,BG_BLUE
};

class ConsoleBase {
protected:
    std::ostream& consoleCodeHandling(std::ostream& os, ConsoleCode consoleCode);
};

class ConsoleString : public ConsoleBase{
public:
    ConsoleString() = default;

    std::string stream() {
        return oss.str();
    }

    template<typename OutputType>
    ConsoleString& operator<<(OutputType&& output) {
        oss << output;
        return *this;
    }
    template<typename OutputType>
    ConsoleString& operator<<(OutputType& output){
        oss << output;
        return *this;
    }
    ConsoleString& operator<<(ConsoleCode consoleCode);
    ConsoleString& operator<<(ConsoleString& consoleString);

private:
    std::ostringstream oss;
};

class Console : public ConsoleBase {
public:
    Console();

    template<typename OutputType>
    Console& operator<<(OutputType&& output) {
        os << output;
        return *this;
    }
    template<typename OutputType>
    Console& operator<<(OutputType& output) {
        os << output;
        return *this;
    }
    Console& operator<<(ConsoleCode consoleCode);
    Console& operator<<(ConsoleString& consoleString);
private:
    std::ostream& os;
};

class  {
public:
    static char revealChar();
    static char pullChar();
    static void showChar();
private:
    static char buffer;
    static Console console;
};


