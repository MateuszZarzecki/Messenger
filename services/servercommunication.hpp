#pragma once

#include "SFML/Network.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

std::string loginUser(sf::Http http, std::string username, std::string password);
std::string registerUser(sf::Http http, std::string username, std::string password);
std::string checkExistUser(sf::Http http, std::string username);
