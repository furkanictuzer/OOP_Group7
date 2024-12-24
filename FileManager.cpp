#include "FileManager.h"
#include "User.h"
#include "Category.h"
#include "Expense.h"
#include "DateUtils.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

void FileManager::saveDataToFile(const User* user) {
    json jsonData;

    // Kullanıcı verisini JSON nesnesine yaz
    jsonData["user_id"] = user->getUserId();
    jsonData["username"] = user->getUserName();
    jsonData["balance"] = user->getBalance();
    jsonData["password"] = user->getPassword();    

    // Kategoriler
    jsonData["categories"] = json::array();
    for (const auto& category : user->getCategories()) {
        json categoryData;
        categoryData["name"] = category.getCategoryName();
        categoryData["expense"] = json::array();

        for (const auto& expense : category.getExpenses()) {
            json expenseData;
            expenseData["id"] = expense->getId();
            expenseData["amount"] = expense->getAmount();
            expenseData["date"] = DateUtils::timePointToString(expense->getDate());
            expenseData["description"] = expense->getDescription();
            categoryData["expense"].push_back(expenseData);
        }

        jsonData["categories"].push_back(categoryData);
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

User FileManager::loadDataFromFile() {
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for reading.\n";
        return User(1, "", "", 0); // Return an empty User object
    }

    json jsonData;
    inFile >> jsonData;

    int id = jsonData["user_id"].get<int>();
    std::string username = jsonData["username"].get<std::string>();
    double balance = jsonData["balance"].get<double>();
    std::string password = jsonData["password"].get<std::string>();

    User user(id, username, password, balance);

    for (const auto& categoryData : jsonData["categories"]) {
        Category category(categoryData["name"].get<std::string>());

        for (const auto& expenseData : categoryData["expense"]) {
            Expense* expense = new Expense(
                expenseData["id"].get<int>(),
                expenseData["amount"].get<double>(),
                DateUtils::stringToTimePoint(expenseData["date"].get<std::string>()),
                expenseData["description"].get<std::string>(),
                &category
            );
            category.addExpense(expense);
        }

        user.addCategory(category);
    }

    std::cout << "Data loaded successfully from user_data.json.\n";
    return user;
}

bool FileManager::fileExists() {
    std::ifstream file(fileName);
    return file.good();
}

bool FileManager::doesUserExist(const std::string& username) {
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for reading.\n";
        return false;
    }

    json jsonData;
    inFile >> jsonData;

    if (jsonData["username"].get<std::string>() == username) {
                return true;
    }

    return false;
}
