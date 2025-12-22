#pragma once
#include <iostream>

#include "serverBase.hpp"

class WebUserAPI : public APIBase {
public:  
    void listUsers(std::string listCount, std::string usernameQuery, std::string startIndex) {}
};