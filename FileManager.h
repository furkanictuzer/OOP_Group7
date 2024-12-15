#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager {
private:
    std::string filePath;

public:
    void saveDataToFile(const void* data);
    void* loadDataFromFile();
    bool fileExists();
};

#endif // FILEMANAGER_H
