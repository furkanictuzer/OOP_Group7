#ifndef AUTHENTICATIONMANAGER_H
#define AUTHENTICATIONMANAGER_H

#include "FileManager.h"
#include <iostream>

using namespace std;

class AuthenticationManager
{
    public:
    bool tryToLogin(string username, string password);
    bool tryToRegister(string username, string password);
};

#endif // AUTHENTICATIONMANAGER_H