#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <string>
#include "User.h"

#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class FileManager {
private:
    std::string filePath;
    std::string fileName = "user_data.json";

public:
    void saveDataToFile(const User* user);
    User loadDataFromFile();
    bool fileExists();
};

#endif // FILEMANAGER_H
