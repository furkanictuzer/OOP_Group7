#include "AuthenticationManager.h"

/**
 * @brief Attempts to log in a user with the given username and password.
 * 
 * This function checks if the user exists in the file system and verifies 
 * the provided password against the stored password.
 * 
 * @param username The username of the user trying to log in.
 * @param password The password of the user trying to log in.
 * @return true if the login is successful, false otherwise.
 */
bool AuthenticationManager::tryToLogin(string username, string password)
{
    cout << "Trying to login" << endl;
    if (FileManager::doesUserExist(username))
    {
        FileManager::loadDataFromFile();

        if (FileManager::getMainUserPawword() == password)
        {
            return true;
        }
    }

    std::cout << "Username does not exist" << std::endl;

    return false;
}

/**
 * @brief Attempts to register a new user with the given username and password.
 * 
 * This function creates a new user and initializes default categories 
 * for expense tracking. The user's data is then saved to the file system.
 * 
 * @param username The username for the new user.
 * @param password The password for the new user.
 * @return true if the registration is successful, false otherwise.
 */
bool AuthenticationManager::tryToRegister(string username, string password)
{
    User user(1, username, password, 0);

    Category* food = new Category("Food");
    Category* entertainment = new Category("Entertainment");
    Category* transportation = new Category("Transportation");
    Category* utilities = new Category("Utilities");
    Category* health = new Category("Health");
    Category* other = new Category("Other");

    user.addCategory(*food);
    user.addCategory(*entertainment);
    user.addCategory(*transportation);
    user.addCategory(*utilities);
    user.addCategory(*health);
    user.addCategory(*other);

    FileManager::saveDataToFile(&user);
    
    return true;
}
