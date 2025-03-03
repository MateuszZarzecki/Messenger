#include <iostream>
#include <SFML/Network.hpp>
#include <thread>
#include "atomicadv.hpp"

struct Connection {
public:
    Connection();

    AtomicAdv<std::string> sessionId = AtomicAdv<std::string>("session");
    std::string username="";
    std::string password="";
    std::string repeatPassword="";
    std::string email="";

    sf::Http serverHttpConn = sf::Http("http://130.162.35.167", 1880);
    std::thread* authorisationThread = new std::thread();

    enum Status {
        //2xx: success
        Ok = 200, //Most common code returned when operation was successful
        //4xx: client error
        FailedExecution = 400, //The server didn't perform an intended action
        BadRequest = 401, //The server couldn't resolve request due to client error (e.g. wrong parameters syntax)
        //5xx: server error
        InternalServerError = 500 // The server encountered unexpected error
    };
};
