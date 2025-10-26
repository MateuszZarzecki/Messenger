#include <iostream>

#include "authenticationMenu.hpp"
#include "menuBase.hpp"
#include "input.hpp"
#include "consoleUtils.hpp"
#include "menuManager.hpp"
#include "localUserApi.hpp"

#include <sstream>

#include <limits>


//Termination Codes can be outputed for debug reasons

int main() {

    // MenuManager menuManager;
    // menuManager.display();
    ReturnData<T<S,I,F>> returnData(Triplet<std::string,int,float>("tripletString",1,2.2));
    std::cout << returnData.data.first << " " << returnData.data.second  << " " << returnData.data.third << " ";
    //Finish:
    return 0;
}
