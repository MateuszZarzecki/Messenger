#include "localUserApi.hpp"

void LocalUserAPI::login(std::string identifier, std::string password) {

    std::string api = "/messenger/api/user/login";
    json body = {{"serverConn", {{"username", identifier}, {"password", password}}}};
    json response = sendRequest(api, body);

    if(response["statusCode"])
    sessionId = response["sessionId"];

}
void LocalUserAPI::signUp(std::string email, std::string username, std::string password) {

    std::string api = "/messenger/api/user/register";
    json body = {"serverConn", {{"email", email}, {"username", username}, {"password", password}}};
    json response = sendRequest(api, body);
}
void LocalUserAPI::settings() {

}
