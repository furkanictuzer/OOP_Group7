#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "User.h"
#include "Category.h"
#include "Expense.h"
#include "DateUtils.h"

using json = nlohmann::json;

class FileManager {
public:
    static void saveDataToFile(const User* user);
    static bool loadDataFromFile();
    static bool fileExists();
    static bool doesUserExist(const std::string& username);
    static User& getMainUser();
    static string getMainUserPawword();
    static void setMainUser(const User& user);

private:
    static User main_user;
    static const std::string fileName;

};

#endif // FILE_MANAGER_H
