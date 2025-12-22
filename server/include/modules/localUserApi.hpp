#pragma once
#include "serverBase.hpp"

class LocalUserAPI : public APIBase {
public:
    void login(std::string identifier, std::string password);
    void signUp(std::string email, std::string username, std::string password);
    void settings();
};
