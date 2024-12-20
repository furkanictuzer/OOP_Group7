#include "FileManager.h"

void FileManager::saveDataToFile(const User* user) {
   json jsonData;

    // Kullanıcı verisini JSON nesnesine yaz
    jsonData["user_id"] = user->getUserId();
    jsonData["username"] = user->userInfo();
    jsonData["balance"] = user->getBalance();

    // Kategoriler
    jsonData["categories"] = json::array();
    for (const auto& category : user->getCategories()) {
        jsonData["categories"].push_back(category.getCategoryName());
    }

    // Dosyayı aç ve JSON'u yaz
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << jsonData.dump(4); // 4 boşluklu girinti
        outFile.close();
        std::cout << "Data saved successfully to user_data.json.\n";
    } else {
        std::cerr << "Failed to open file for writing.\n";
    }
}

void FileManager::loadDataFromFile(User& user) {
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for reading.\n";
        return;
    }

    json jsonData;
    inFile >> jsonData;
    inFile.close();

    // JSON verilerini User nesnesine yükle
    int user_id = jsonData["user_id"];
    std::string username = jsonData["username"];
    double balance = jsonData["balance"];

    user = User(user_id, username, "default_password", balance);

    // Kategorileri yükle
    for (const auto& categoryName : jsonData["categories"]) {
        user.addCategory(Category(categoryName));
    }

    std::cout << "Data loaded successfully from user_data.json.\n";
}

bool FileManager::fileExists() {
    std::ifstream file(fileName);
    return file.good();
}
