#pragma once

#include "SFML/Network.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include "nlohmann/json.hpp"
#include <QDebug>
using json = nlohmann::json;

json loginUser(sf::Http& http, std::string username, std::string password);
json registerUser(sf::Http&http, std::string username, std::string password);

//DEBUG
void checkConnection(sf::Http& http);
