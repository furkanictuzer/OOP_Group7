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