#include "apihandler.hpp"

//"http://130.162.35.167",1880
//"/messenger/api/authentication/userExists"

json fetchSessionId()
{
    std::ifstream iFile;
    json sessionIdJson;
    iFile.open("assets/sessionId.json");

    if(iFile.good())
    {
        sessionIdJson = json::parse(iFile);
        qDebug() << "Session ID Fetched";
    }
    else
    {
        qDebug() << "Fetching session ID Failed";
        sessionIdJson = json();
    }
    iFile.close();
    return sessionIdJson;
}

bool saveSessionId(std::string& sessionId)
{
    bool saved = true;
    std::ofstream oFile;
    oFile.open("assets/sessionId.json");

    if(oFile.good())
    {
        json sessionIdJson;
        sessionIdJson["sessionId"] = sessionId;

        oFile << sessionIdJson.dump();
        qDebug() << "Session ID Saved";
    }
    else
    {
        qDebug() << "Saving session ID Failed";
        saved = false;
    }
    oFile.close();
    return saved;

}
void loginUser(sf::Http& http, std::string username, std::string password)
{
    sf::Http::Request request;
    request.setHttpVersion(1,1);
    request.setUri("/messenger/api/validSession");
    request.setMethod(sf::Http::Request::Post);
    request.setField("Content-type", "application/json");

    //Connection::sessionId.store(fetchSessionId());

    json requestJson;
    //requestJson["sessionId"] = Connection::sessionId.load();
    requestJson["username"] = username;
    requestJson["password"] = password;

    request.setBody(requestJson.dump());
    sf::Http::Response responseRawData = http.sendRequest(request);

    if(responseRawData.getStatus() == sf::Http::Response::Ok)
    {
        json responseJson = json::parse(responseRawData.getBody());
        if(responseJson["valid"])
        {
            qDebug() << "Logged in Succesfully";
            //qDebug() << "Your old session ID: " << Connection::sessionId.load();
        }
        else
        {
            request.setUri("messenged/api/authentication/login");
            responseRawData = http.sendRequest(request);
            responseJson = json::parse(responseRawData.getBody());
            if(responseJson[""]) {

            }

            qDebug() << "Incorrect data";
        }
    }
    else
    {
        qDebug() << "no response was returned \n";
    }
}
void registerUser(sf::Http& http, std::string username, std::string password)
{
    sf::Http::Request request;
    request.setHttpVersion(1,1);
    request.setUri("/messenger/api/authentication/register");
    request.setMethod(sf::Http::Request::Post);
    request.setField("Content-type", "application/json");

    json requestJson;
    requestJson["username"] = username;
    requestJson["password"] = password;

    request.setBody(requestJson.dump());
    sf::Http::Response responseRawData = http.sendRequest(request);

    if(responseRawData.getStatus() == sf::Http::Response::Ok)
    {
        json responseJson = json::parse(responseRawData.getBody());
        if(responseJson["statusCode"] == 200)
        {
            qDebug() << "Registered Succesfully";
            qDebug() << "Your session ID: " << responseJson["sessionId"].get<std::string>().c_str();
            //Connection::sessionId.store(responseJson["sessionId"].get<std::string>());
        }
        else
        {
            qDebug() << "Incorrect data";
        }
    }
    else
    {
        qDebug() << "no response was returned \n";
    }

}
void checkConnection(sf::Http& http)
{
    sf::Http::Request request;
    request.setHttpVersion(1,1);
    request.setUri("/messenger/api/checkConnection");
    request.setMethod(sf::Http::Request::Post);
    request.setField("Content-type", "application/json");

    json testConnectionJson;
    testConnectionJson["message"] = "trying to connect";
    testConnectionJson["statusCode"] = 200;

    request.setBody(testConnectionJson.dump());
    sf::Http::Response responseRawData = http.sendRequest(request);

    if(responseRawData.getStatus() == sf::Http::Response::Status::Ok)
    {
        json responseJson = json::parse(responseRawData.getBody());

        qDebug() << "message: "  << responseJson["message"].get<std::string>().c_str() << '\n'
                 << "status: " << responseJson["statusCode"].get<int>() << '\n';
    }
    else
    {
        qDebug() << "no response was returned \n";
    }
}

unsigned int AuthorizationClient::countCharsInString (std::string& chars, std::string& inputString)
{
    unsigned int count = 0;
    std::size_t firstIndex = inputString.find_first_of(chars);
    while(firstIndex != std::string::npos)
    {
        std::size_t lastIndex= inputString.find_first_not_of(chars, firstIndex);
        count += lastIndex - firstIndex + 1;
        firstIndex = lastIndex;
    }
    return count;
}

bool AuthorizationClient::validateLoginInput()
{
    std::string usernameStdString = "";//Connection::username;
    std::string passwordStdString = "";//Connection::password;

    std::string digits = "0123456789";
    std::string letters = "abcdefghijklmnopqrstuvwxyz";

    unsigned int usernameDigitsCount = countCharsInString(digits, usernameStdString);
    unsigned int usernameLettersCount = countCharsInString(letters, usernameStdString);
    unsigned int usernameSpecialCharsCount = usernameStdString.length() - usernameDigitsCount - usernameLettersCount;


    bool validInputs = true;

    if(usernameDigitsCount < 2) {
        qDebug() << "Too few numbers";
        validInputs = false;
    }
    if(usernameLettersCount < 5) {
        qDebug() << "Too few letters";
        validInputs = false;
    }
    if(usernameSpecialCharsCount < 2) {
        qDebug() << "Too few special characters";
        validInputs = false;
    }
    if(passwordStdString.length() < 4) {
        qDebug() << "Password has to few characters";
        validInputs = false;
    }
    return validInputs;
}
bool AuthorizationClient::validateRegisterInput()
{
    std::string usernameStdString = "";//Connection::username;
    std::string passwordStdString = "";//Connection::password;
    std::string repeatPasswordStdString = "";//Connection::repeatPassword;
    std::string emailStdString = "";//Connection::email;


    std::string digits = "0123456789";
    std::string letters = "abcdefghijklmnopqrstuvwxyz";
    std::string specialChars = "!@#$%^&*()_+-={}[]|:;<>,.?/~";

    unsigned int usernameDigitsCount = countCharsInString(digits, usernameStdString);
    unsigned int usernameLettersCount = countCharsInString(letters, usernameStdString);
    unsigned int usernameSpecialCharsCount = usernameStdString.length() - usernameDigitsCount - usernameLettersCount;

    bool validInputs = true;

    if(usernameDigitsCount < 2) {
        qDebug() << "Too few numbers";
        validInputs = false;
    }
    if(usernameLettersCount < 5) {
        qDebug() << "Too few letters";
        validInputs = false;
    }
    if(usernameSpecialCharsCount < 2) {
        qDebug() << "Too few special characters";
        validInputs = false;
    }
    if(passwordStdString.length() < 4) {
        qDebug() << "Password has to few characters";
        validInputs = false;
    }
    if(repeatPasswordStdString != passwordStdString) {
        qDebug() << "Password and repeated password are different";
        validInputs = false;
    }
    if(emailStdString.find('@') == std::string::npos) {
        qDebug() << "Email doesnt have '@'";
        validInputs = false;
    }
    return validInputs;
    //(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|"(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9]))\.){3}(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9])|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\])

}
