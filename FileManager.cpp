#include "FileManager.h"
#include "User.h"
#include "Category.h"
#include "Expense.h"
#include "DateUtils.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

const std::string FileManager::fileName = "user_data.json";
User FileManager::main_user(0,"", "", 0);

void FileManager::saveDataToFile(const User* user) {
    std::ofstream outFile(fileName);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    json jsonData;
    jsonData["user_id"] = user->getUserId();
    jsonData["username"] = user->getUserName();
    jsonData["balance"] = user->getBalance();
    jsonData["password"] = user->getPassword();

    for (const auto& category : user->getCategories()) {
        json categoryData;
        categoryData["name"] = category.getCategoryName();

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

    outFile << jsonData.dump(4);
    std::cout << "Data saved successfully to user_data.json.\n";
}

bool FileManager::loadDataFromFile() {
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for reading.\n";
        return false;
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

    setMainUser(user);
    return true;
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

User FileManager::getMainUser() {
    return main_user;
}

void FileManager::setMainUser(const User& user) {
    main_user = user;
}
