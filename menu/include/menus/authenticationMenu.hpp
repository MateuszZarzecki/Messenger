#pragma once
#include <iostream>

#include "menuBase.hpp"
#include "localUserApi.hpp"
#include "mainMenu.hpp"

class AuthenticationMenu : public MenuBase
{
public:     void display() override;
private:    LocalUserAPI localUserApi;
};
class LoginMenu : public MenuBase
{
public:     void display() override;
private:    LocalUserAPI localUserApi;
};
class SignUpMenu : public MenuBase
{
public:     void display() override;
private:    LocalUserAPI localUserApi;
};
class VerifyEmailMenu : public MenuBase
{
public:     void display() override;
private:    LocalUserAPI localUserApi;
};
