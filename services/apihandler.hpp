#pragma once

#include <sstream>
#include <vector>
#include <iterator>
#include "nlohmann/json.hpp"
#include <QDebug>
#include <fstream>
#include <QMainWindow>
#include <thread>
#include <iostream>
#include <SFML/Network.hpp>
#include "connection.hpp"

using json = nlohmann::json;

class ServerCommunication {
public:
    void sendBackgroundRequest();
    Connection* conn;
};

class AuthorizationClient : public ServerCommunication{
public:
    AuthorizationClient (Connection* conn);
    void loginUser(std::string username, std::string password);
    void registerUser(std::string username, std::string password);

private:

    json fetchSessionId();
    bool saveSessionId(std::string& sessionId);

    bool validateLoginInput();
    bool validateRegisterInput();
    unsigned int countCharsInString (std::string& chars, std::string& inputString);
};

class ChatClient {

};

//DEBUG
void checkConnection(sf::Http& http);
void checkJwt(sf::Http& http);


