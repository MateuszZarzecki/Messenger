#pragma once
#include <iostream>

#include "menuBase.hpp"
#include "localUserApi.hpp"
#include "mainMenu.hpp"

class AuthenticationMenu : public UIVerticalLayout
{
public:     OutputString& display() override;
private:    LocalUserAPI localUserApi;
};
class LoginMenu : public UIVerticalLayout
{
public:     OutputString& display() override;
private:    LocalUserAPI localUserApi;
};
class SignUpMenu : public UIVerticalLayout
{
public:     OutputString& display() override;
private:    LocalUserAPI localUserApi;
};
class VerifyEmailMenu : public UIVerticalLayout
{
public:     OutputString& display() override;
private:    LocalUserAPI localUserApi;
};
