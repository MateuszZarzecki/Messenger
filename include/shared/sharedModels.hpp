#pragma once
#include <iostream>
#include <vector>

class User {
public:
    User(std::string username, std::string password, std::string email, std::string phoneNumber="");
    std::string username, password, email, phoneNumber;
};
class Chat {
public:
    Chat(std::string chatName);
    std::string chatName;
};
struct SocialNetworkRepository { 
public:
    User user;
    std::vector<User> friends;
    std::vector<Chat> chats;
};
