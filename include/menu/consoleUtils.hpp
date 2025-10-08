//STATIC set methods ??? are they nessecary

#pragma once
#include <iostream>
#include <conio.h>

enum class ConsoleCode {
    NLINE,DEL_PREV_CHAR,DEL_LINE,CLEAR_PAGE,
    TX_WHITE,TX_BLACK,TX_GREEN,TX_RED,TX_BLUE,
    BG_WHITE,BG_BLACK,BG_GREEN,BG_RED,BG_BLUE
};

class Console {
public:
    Console(std::ostream& os);
    char getChar();
    
    template<typename T>
    Console& operator<<(T output) {
        os << output;
        return *this;
    }
    Console& operator<<(ConsoleCode consoleCode);
private:
    std::ostream& os;
    std::pair<int,int> printableChars;
};
