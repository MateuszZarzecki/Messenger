//STATIC set methods ??? are they nessecary

#pragma once
#include <iostream>
#include <sstream>
#include <conio.h>

enum class ConsoleCode {
    NLINE,
    DEL_PREV_CHAR,DEL_LINE,CLEAR_PAGE,
    LOCK,UNLOCK,
    TX_WHITE,TX_BLACK,TX_GREEN,TX_RED,TX_BLUE,
    BG_WHITE,BG_BLACK,BG_GREEN,BG_RED,BG_BLUE
};

//Nazwa OutputStream
class Console {
public:
    Console();
    Console(std::ostream& os);
    char getChar();
    
    template<typename T>
    Console& operator<<(T& output) {
        buffer << output;
        flush();
        return *this;
    }
    template<typename T>
    Console& operator<<(T&& output) {
        buffer << output;
        flush();
        return *this;
    }

    Console& operator<<(ConsoleCode consoleCode);
    Console& operator<<(std::ostream& (*manip)(std::ostream&));

private:
    std::ostringstream buffer;
    std::ostream& sink;
    std::pair<int,int> printableChars;

    bool locked;

    void flush();
};
