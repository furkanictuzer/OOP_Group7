#include <iostream>
#include <string>
#include <vector>

#include "User.h"
#include <iostream>
#include <fstream>

User::User(int id, const std::string& name, const std::string& pass, double bal)
    : user_id(id), username(name), password(pass), balance(bal) {}

std::string User::userInfo() const {
    return "User ID: " + std::to_string(user_id) +
           ", Username: " + username +
           ", Balance: " + std::to_string(balance);
}

std::string User::getUserName() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

void User::addCategory(const Category& category) {
    categories.push_back(category);
}

void User::removeCategory(const Category& category) {
    for (auto it = categories.begin(); it != categories.end(); ++it) {
        if (it->getCategoryName() == category.getCategoryName()) {
            categories.erase(it);
            break;
        }
    }
}

double User::getBalance() const {
    return balance;
}

Budget User::getCurrentBudget()
{
    this->budgets.at(budgets.size() - 1);
}

void User::updateUserInfo(const std::string& new_username, const std::string& new_password) {
    username = new_username;
    password = new_password;
}

bool User::deleteAccount() {
    
    categories.clear();
    budgets.clear();

    // JSON dosyasını oku
    std::ifstream inputFile("user_data.json");
    if (!inputFile.is_open()) {
        std::cerr << "Could not open user_data.json file.\n";
        return false;
    }

    std::string jsonContent((std::istreambuf_iterator<char>(inputFile)),
                            std::istreambuf_iterator<char>());
    inputFile.close();

    if (jsonContent.empty()) {
        std::cerr << "JSON file is empty.\n";
        return false;
    }

    // silinecek olan user_id yi ara
    std::string searchKey = "\"user_id\": " + std::to_string(user_id);
    size_t idPos = jsonContent.find(searchKey);
    if (idPos == std::string::npos) {
        std::cerr << "User not found.\n";
        return false;
    }

    // kullanıcıyı temsil eden `{}` bloğunu bul
    size_t start = jsonContent.rfind("{", idPos);
    size_t end = jsonContent.find("}", idPos);
    if (start == std::string::npos || end == std::string::npos) {
        std::cerr << "User data is formatted incorrectly.\n";
        return false;
    }

    // kullanıcıyı sil
    jsonContent.erase(start, end - start + 1);

    // Gereksiz virgülü temizle
    size_t commaPos = jsonContent.find(",\n", start);
    if (commaPos != std::string::npos) {
        jsonContent.erase(commaPos, 2); // `,` ve yeni satır karakterlerini kaldır
    }

    // Güncellenmiş JSON'u dosyaya yaz
    std::ofstream outputFile("user_data.json");
    if (!outputFile.is_open()) {
        std::cerr << "Could not write user_data.json file.\n";
        return false;
    }

    outputFile << jsonContent;
    outputFile.close();

    return true;
}

int User::getUserId() const {
    return user_id;
}

vector<Category> User::getCategories() const
{
    return categories;
}

Category* User::getCategoryByName(const std::string& name)
{
    for (auto& category : categories) {
        if (category.getCategoryName() == name) {
            return &category;
        }
    }

    throw std::invalid_argument("Category not found.");
}

int User::getExpenseCount() const
{
    int count = 0;
    for (const auto& category : categories) {
        count += category.getExpenseCount();
    }
    return count;
}