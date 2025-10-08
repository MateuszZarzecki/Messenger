#include "sharedModels.hpp"

User::User(std::string username, std::string password, std::string email, std::string phoneNumber)
    : username(username), password(password), email(email), phoneNumber(phoneNumber) {}

Chat::Chat(std::string chatName)
    : chatName(chatName) {}
