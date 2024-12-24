#include "AuthenticationManager.h"


AuthenticationManager::AuthenticationManager(FileManager fileManager) : fileManager(fileManager) {}

bool AuthenticationManager::tryToLogin(string username, string password)
{
    if (fileManager.doesUserExist(username))
    {
        User user = fileManager.loadDataFromFile();
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
    fileManager.saveDataToFile(&user);
    
    return true;
}