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
//#include "atomicadv.hpp"

using json = nlohmann::json;

class AuthorizationClient {
public:
    void loginUser(sf::Http& http, std::string username, std::string password);
    void registerUser(sf::Http& http, std::string username, std::string password);

private:
    json fetchSessionId();
    bool saveSessionId();

    bool validateLoginInput();
    bool validateRegisterInput();
    unsigned int countCharsInString (std::string& chars, std::string& inputString);
};

class ChatClient {

};

//DEBUG
void checkConnection(sf::Http& http);
void checkJwt(sf::Http& http);

// namespace Connection {

//     AtomicAdv<std::string> sessionId;
//     std::string username="";
//     std::string password="";
//     std::string repeatPassword="";
//     std::string email="";

//     sf::Http serverHttpConn("http://130.162.35.167", 1880);
//     std::thread* authorisationThread = new std::thread();

//     enum Status {
//         //2xx: success
//         Ok = 200, //Most common code returned when operation was successful
//         //4xx: client error
//         FailedExecution = 400, //The server didn't perform an intended action
//         BadRequest = 401, //The server couldn't resolve request due to client error (e.g. wrong parameters syntax)
//         //5xx: server error
//         InternalServerError = 500 // The server encountered unexpected error
//     };
// };
