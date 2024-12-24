#include "AuthenticationManager.h"


bool AuthenticationManager::tryToLogin(string username, string password)
{
    if (FileManager::doesUserExist(username))
    {
        FileManager::loadDataFromFile();
        User user = FileManager::getMainUser();
        if (user.getPassword() == password)
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