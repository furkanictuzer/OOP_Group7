#include "AuthenticationManager.h"


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

bool AuthenticationManager::tryToRegister(string username, string password)
{
    User user(1, username, password, 0);
    FileManager::saveDataToFile(&user);
    
    return true;
}