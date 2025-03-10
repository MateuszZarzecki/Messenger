#include "connection.hpp"

Connection::Connection()
    : sessionId(""),
    username(""),
    password(""),
    repeatPassword(""),
    email(""),
    serverHttpConn(sf::Http("http://130.162.35.167",1880)),
    authorizationThread(new std::thread())
{}
