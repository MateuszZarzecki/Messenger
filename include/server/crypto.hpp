#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>  

#include "nlohmann/json.hpp"
using json = nlohmann::json;

class Crypto {
public:    
    void changeKey(std::string key);
    std::string hash(std::string input);
    std::string encode(std::string input);
    std::string decode(std::string input);
private:
    static std::string key;
};