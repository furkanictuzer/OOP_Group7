#ifndef AUTHENTICATIONMANAGER_H
#define AUTHENTICATIONMANAGER_H

#include "FileManager.h"
#include "Category.h"
#include <iostream>

using namespace std;

/**
 * @class AuthenticationManager
 * @brief This class is responsible for managing user authentication processes such as login and registration.
 */
class AuthenticationManager
{
    public:
    /**
     * @brief Attempts to log in a user with the provided username and password.
     * 
     * This function checks the provided credentials against stored data and returns true if login is successful.
     * 
     * @param username The username of the user trying to log in.
     * @param password The password of the user trying to log in.
     * @return true if the login attempt is successful, false otherwise.
     */
    bool tryToLogin(string username, string password);

    /**
     * @brief Attempts to register a new user with the provided username and password.
     * 
     * This function checks if the username is available and registers the user if the conditions are met.
     * 
     * @param username The username the user wants to register.
     * @param password The password the user wants to set for their account.
     * @return true if the registration is successful, false otherwise.
     */
    bool tryToRegister(string username, string password);
};

#endif // AUTHENTICATIONMANAGER_H
