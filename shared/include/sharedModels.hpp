#pragma once
#include <string>
#include <vector>

enum class Theme { WHITE,BLACK,COLORFUL };

class User;

class Chat
{
public:
    Chat(std::string chatName, long long creationTimestamp);

    enum class ChatType { PRIVATE_UNKNOWN,PRIVATE_FRIEND,GROUP };
    enum class Role { MEMBER=-1,ADMIN,OWNER };

    class Member
    {
    public:
        Role role;
        User* user;
        int lastReadMessage;
    };
    class Message
    {
    public:
        Member* sender;
        std::string message;
        Message* reply; // ?
        long long sendTimestamp;
        bool edited;
    };

    std::string chatName;
    long long creationTimestamp;
    std::vector<Message> messages;
    std::vector<Member> members;
    ChatType chatType;
};
class User
{
public:
    User(std::string username,std::string email={},std::string phoneNumber={});

    std::vector<Chat> chats;
    std::vector<User> friends;
    std::vector<std::string> previousIps;
    std::string username, email, phoneNumber;
};

class PrimeUser : public User
{
public:
    PrimeUser(std::string username, std::string password, std::string email, std::string phoneNumber="");

    class Invitation
    {
    public:
        User* sender;
        long long sendTimestamp;
    };

    std::vector<Invitation> invitations;
    std::string password;

    bool notificationsOn;
    Theme theme;
};


