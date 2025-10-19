#include "localUserApi.hpp"

void LocalUserAPI::login(std::string identifier, std::string password) {

    // json response;
    // try {
    //     std::string api = "/messenger/api/user/login";
    //     json body = json({{"serverConn", {{"username", identifier}, {"password", password}}}});
    //     std::cout << "[login] body:\n" << body.dump(2) << std::endl;

    //     response = sendRequest(api, body);
    //     std::cout << "[login] response:\n" << response.dump(2) << std::endl;
    // }
    // catch (const std::exception& e) {
    //     std::cerr << "[login] exception: " << e.what() << std::endl;
    //     throw; // na czas debugowania NIE tłum — pozwól zobaczyć call stack
    // }

    std::string api = "/messenger/api/user/login";
    json body = {{"serverConn", {{"username", identifier}, {"password", password}}}};
    std::cout << body.dump(2);
    json response = sendRequest(api, body);

    std::cout << response.dump(2);
    // try{

    // }
    // catch(...) {
    //     std::cout << "json error";
    // }

    // if(response["statusCode"])
    // sessionId = response["sessionId"];

}
void LocalUserAPI::signUp(std::string email, std::string username, std::string password) {

    std::string api = "/messenger/api/user/register";

    json body = {"serverConn", {{"email", email}, {"username", username}, {"password", password}}};
    json response = sendRequest(api, body);
}
void LocalUserAPI::settings() {

}
