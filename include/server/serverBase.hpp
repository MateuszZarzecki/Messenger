#pragma once
#include <iostream>
#include <exception>
#include <sstream>
#include <winsock2.h>

#include "sharedModels.hpp"
#include <HTTPRequest.hpp>
#include <json.hpp>
using json = nlohmann::json;
 
class APIBase {
public:
    APIBase();
protected:
    User* user;
    std::string host, sessionId;
    unsigned short port;
    json apiStatusCodes;

    std::string getUrl(std::string api);
    json sendRequest(std::string api, json body);
    json getServerConnectionPackage();
    void fetchAPIStatusCodes();
};
