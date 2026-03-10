#pragma once
#include <iostream>

#include "menuBase.hpp"
#include "localUserApi.hpp"
#include "mainMenu.hpp"

class AuthenticationMenu : public UIMenuLayout
{
public:     OutputString& display() override;
private:    LocalUserAPI localUserApi;
};
// class LoginMenu : public UIMenuLayout
// {
// public:     OutputString& display() override;
// private:    LocalUserAPI localUserApi;
// };
// class SignUpMenu : public UIMenuLayout
// {
// public:     OutputString& display() override;
// private:    LocalUserAPI localUserApi;
// };
// class VerifyEmailMenu : public UIMenuLayout
// {
// public:     OutputString& display() override;
// private:    LocalUserAPI localUserApi;
// };
