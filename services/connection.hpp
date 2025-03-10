#include <iostream>
#include <SFML/Network.hpp>
#include <thread>
#include "atomicadv.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct Connection {
public:
    Connection();

    AtomicAdv<std::string> sessionId;
    AtomicAdv<std::string> username;
    AtomicAdv<std::string> password;
    AtomicAdv<std::string> repeatPassword;
    AtomicAdv<std::string> email;
    AtomicAdv<json> serverConnTemplateJosn;

    AtomicAdv<sf::Http> serverHttpConn;
    std::thread* authorisationThread;

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
