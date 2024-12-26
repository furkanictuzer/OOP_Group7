#include "FileManager.h"
#include "User.h"
#include "Category.h"
#include "Expense.h"
#include "RepeatedExpense.h"
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

            // Check if the expense is a RepeatedExpense
            const RepeatedExpense* repeatedExpense = dynamic_cast<const RepeatedExpense*>(expense);
            if (repeatedExpense) {
                expenseData["repeat_count"] = repeatedExpense->getRepeatCount();
            }

            categoryData["expenses"].push_back(expenseData);
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
    std::cout << "User ID: " << id << ", Username: " << username << ", Balance: " << balance << ", Password: " << password << std::endl;

    User user(id, username, password, balance);

    for (const auto& categoryData : jsonData["categories"]) {
        Category category(categoryData["name"].get<std::string>());

        for (const auto& expenseData : categoryData["expenses"]) {
            int expenseId = expenseData["id"].get<int>();
            double amount = expenseData["amount"].get<double>();
            auto date = DateUtils::stringToTimePoint(expenseData["date"].get<std::string>());
            std::string description = expenseData["description"].get<std::string>();

            // Check if the expense has a repeat_count field
            if (expenseData.contains("repeat_count")) {
                int repeatCount = expenseData["repeat_count"].get<int>();
                RepeatedExpense* repeatedExpense = new RepeatedExpense(expenseId, amount, date, description, &category, repeatCount, std::chrono::hours(30 * 24));
                category.addExpense(repeatedExpense);
            } else {
                Expense* expense = new Expense(expenseId, amount, date, description, &category);
                category.addExpense(expense);
            }
        }

        user.addCategory(category);
    }

    main_user = user;
    std::cout << "Data loaded successfully from user_data.json.\n";
    return true;
}

bool FileManager::fileExists() {
    std::ifstream file(fileName);
    return file.good();
}

void FileManager::deleteAllUser() {
    std::ofstream outFile(fileName);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    // Write an empty JSON array to the file
    outFile << "[]";
    outFile.close();
    std::cout << "All user data deleted successfully.\n";
}

void FileManager::deleteUser(const std::string& username) 
{
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for reading.\n";
        return;
    }

    json jsonData;
    inFile >> jsonData;
    inFile.close();

    // Remove the user with the specified username
    jsonData.erase(std::remove_if(jsonData.begin(), jsonData.end(),
        [&username](const json& user) {
            return user["username"].get<std::string>() == username;
        }), jsonData.end());

    // Write the updated data back to the file
    std::ofstream outFile(fileName);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    outFile << jsonData.dump(4);
    outFile.close();
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

User& FileManager::getMainUser() {
    return main_user;
}

void FileManager::setMainUser(const User& user) {
    main_user = user;
}

string FileManager::getMainUserPawword()
{
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for reading.\n";
        return "";
    }

    json jsonData;
    inFile >> jsonData;

    return jsonData["password"].get<std::string>();
}
