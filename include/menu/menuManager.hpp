#pragma once
#include <iostream>

#include "authenticationMenu.hpp"
#include "chatMenu.hpp"
#include "mainMenu.hpp"

class MenuManager {
public:
    MenuManager();
    ~MenuManager();
    void display();
private:
    MenuRepository menuRepository;
};

//key

//

//nie ma klucza
//getKeyAPI 
//zapis klucza
//szyfrowanie kluczem
//po x czasie klucz sie resetuje

// Logowanie bez klucza
  