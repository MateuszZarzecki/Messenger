#include "sharedModels.hpp"

User::User(std::string username,std::string email,std::string phoneNumber)
    : username(username), email(email), phoneNumber(phoneNumber) {}

Chat::Chat(std::string chatName, long long creationTimestamp)
    : chatName(chatName), creationTimestamp(creationTimestamp) {}

PrimeUser::PrimeUser(std::string username, std::string password, std::string email, std::string phoneNumber)
    : User(username,email,phoneNumber)
{
    this->password = password;
}
