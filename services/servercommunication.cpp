#include "services/servercommunication.hpp"

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

json loginUser(sf::Http& http, std::string username, std::string password)
{
    qDebug() << "start";

    sf::Http::Request request;
    request.setHttpVersion(1,1);
    request.setUri("/messenger/api/authentication/login");
    request.setMethod(sf::Http::Request::Post);

    json requestJson;
    requestJson["username"] = username;
    requestJson["password"] = password;
    qDebug() << "create request";
    qDebug() << requestJson.dump();

    request.setBody(requestJson.dump());
    sf::Http::Response responseRawData = http.sendRequest(request);
    qDebug() << "get response";

    if(responseRawData.getStatus() == sf::Http::Response::Ok)
    {
        json responseJson = json::parse(responseRawData.getBody());
        qDebug() << responseJson.dump();
        return responseJson;
    }
    else
    {
        qDebug() << "no response was returned \n";
        return json();
    }

}
json registerUser(sf::Http& http, std::string username, std::string password)
{
    qDebug() << "start";

    sf::Http::Request request;
    request.setHttpVersion(1,1);
    request.setUri("/messenger/api/authentication/register");
    request.setMethod(sf::Http::Request::Post);

    json requestJson;
    requestJson["username"] = username;
    requestJson["password"] = password;

    request.setBody(requestJson.dump());
    sf::Http::Response responseRawData = http.sendRequest(request);

    json responseJson = json::parse(responseRawData.getBody());
    qDebug() << responseJson.dump();

    return responseJson;
}
void checkConnection(sf::Http& http)
{
    qDebug() << "start";

    sf::Http::Request request;
    request.setHttpVersion(1,1);
    request.setUri("/messenger/api/checkConnection");
    request.setMethod(sf::Http::Request::Post);

    json testConnectionJson;
    testConnectionJson["message"] = "trying to connect";
    testConnectionJson["status"] = 100;

    request.setBody(testConnectionJson.dump());
    sf::Http::Response responseRawData = http.sendRequest(request);

    if(responseRawData.getStatus() == sf::Http::Response::Status::Ok)
    {
        json responseJson = json::parse(responseRawData.getBody());

        qDebug() << "message: "  << responseJson["message"].get<std::string>().c_str() << '\n'
                 << "status: " << responseJson["status"].get<int>() << '\n';
    }
    else
    {
        qDebug() << "no response was returned \n";
    }
}

