#include "services/servercommunicatoin.hpp"

//"http://130.162.35.167",1880
//"/messenger/api/authentication/userExists"

//wszystko w funkcjach obslugujacych
//node red - response status, doesUserExists: false / true, kod sesji
//kod sesji tworzy server i przesyla do klienta
//thread do wszystkiego oprocz ui
//sf::Thread
// sf::Thread::launch();
// sf::Thread::terminate();
// sf::Thread::wait()
//blocking nonblocking
//

std::string loginUser(sf::Http http, std::string username, std::string password)
{

}
std::string registerUser(sf::Http http, std::string username, std::string password)
{

}

std::string checkExistUser(sf::Http http, std::string username)
{
    //send and get
    sf::Http::Request request;
    request.setHttpVersion(1,1);
    request.setUri("/messenger/api/authentication/userExists");
    request.setMethod(sf::Http::Request::Get);

    json userJson;
    userJson["usename"] = username;

    request.setBody(userJson.dump());
    sf::Http::Response responseRawData = http.sendRequest(request);

    json responseJson = responseRawData.getBody();

    //process
    if(responseJson["status"]==100)
    {
        if(responseJson["doesUserExists"]==true)
        {
        }
        else
        {

        }
    }

}
