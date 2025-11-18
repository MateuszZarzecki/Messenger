#pragma once
#include <string>
#include <vector>

enum class Theme { WHITE,BLACK,COLORFUL };

struct User;

struct Chat
{
    Chat(std::string chatName, long long creationTimestamp);

    enum class ChatType { PRIVATE_UNKNOWN,PRIVATE_FRIEND,GROUP };
    enum class Role { MEMBER=-1,ADMIN,OWNER };

    struct Member
    {
        Role role;
        User* user;
        int lastReadMessage;
    };
    struct Message
    {
        Member* sender;
        std::string message;
        Message* reference;
        long long sendTimestamp;
        bool edited;
    };

    std::string chatName;
    long long creationTimestamp;
    std::vector<Message> messages;
    std::vector<Member> members;
    ChatType chatType;
};
struct User
{
    User(std::string username,std::string email={},std::string phoneNumber={});

    std::vector<Chat> chats;
    std::vector<User> friends;
    std::vector<std::string> previousIps;
    std::string username, email, phoneNumber;
};

struct PrimeUser : public User
{
    PrimeUser(std::string username, std::string password, std::string email, std::string phoneNumber="");

    struct Invitation
    {
        User* sender;
        long long sendTimestamp;
    };

    std::vector<Invitation> invitations;
    std::string password;

    bool notificationsOn;
    Theme theme;
};


