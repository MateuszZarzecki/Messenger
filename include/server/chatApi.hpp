#pragma once
#include <iostream>

#include "serverBase.hpp"

class ChatAPI : public APIBase {
public:
    void listUsersChats();
    void searchChats(std::string chatName);
    void createChat(std::string chatName);
};
