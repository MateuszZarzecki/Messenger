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
//#include "atomicadv.hpp"

using json = nlohmann::json;

class AuthorizationClient {
public:
    AuthorizationClient (Connection* conn);

    void loginUser(sf::Http& http, std::string username, std::string password);
    void registerUser(sf::Http& http, std::string username, std::string password);

private:
    Connection* conn;

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


