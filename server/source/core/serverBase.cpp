#include "serverBase.hpp"

APIBase::APIBase() {
    host = "130.162.35.167";
    sessionId = "";
    port = 1880;
    apiStatusCodes = json();
}
std::string APIBase::getUrl(std::string api) {
    return "http://" + host + ":" + std::to_string(port) + api;
}
json APIBase::sendRequest(std::string api, json body) {
    try {
        http::Request request{getUrl(api)};
        http::Response response = request.send("POST", body.dump(), {{"Content-Type", "application/json"}});
        return json::parse(response.body.begin(), response.body.end());
    }
    catch (const std::exception& e) {
        std::cerr << "Request failed" << e.what() << std::endl;
        return json();
    }   
}
json APIBase::getServerConnectionPackage() {
    return json({"serverConn", {
                {"username", primeUser->username},
                {"password", primeUser->password},
                {"sessionId", sessionId}}});
}
void APIBase::fetchAPIStatusCodes() {
    std::string api = "/messenger/api/data/getStatusCodes";
    json body = getServerConnectionPackage();
    json response = sendRequest(api, body);
    
    apiStatusCodes = response;
}


