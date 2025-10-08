#include "chatApi.hpp"

void ChatAPI::listUsersChats() {

    std::string api = "/messenger/api/chat/listChats";
    json body = {"serverConn", {getServerConnectionPackage()}};
    json response = sendRequest(api, body);
}
void ChatAPI::searchChats(std::string chatName) {

    std::string api = "/messenger/api/chat/searchChats";
    json body = {{"serverConn", {getServerConnectionPackage()}}, {"chatName", chatName}};
    json response = sendRequest(api, body);
}
void ChatAPI::createChat(std::string chatName) {

    std::string api = "/messenger/api/chat/createChat";
    json body = {{"serverConn", {getServerConnectionPackage()}}, {"chatName", chatName}};
}
