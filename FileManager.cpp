#include "FileManager.h"
#include "User.h"
#include "Category.h"
#include "Expense.h"
#include "RepeatedExpense.h"
#include "Budget.h"
#include "DateUtils.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

const std::string FileManager::fileName = "user_data.json";
User FileManager::main_user(0, "", "", 0);

void FileManager::saveDataToFile(const User *user)
{
    std::ofstream outFile(fileName);
    if (!outFile.is_open())
    {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    json jsonData;
    jsonData["user_id"] = user->getUserId();
    jsonData["username"] = user->getUserName();
    jsonData["balance"] = user->getBalance();
    jsonData["password"] = user->getPassword();

    for (const auto &category : user->getCategories())
    {
        json categoryData;
        categoryData["name"] = category.getCategoryName();

        for (const auto &expense : category.getExpenses())
        {
            json expenseData;
            expenseData["id"] = expense->getId();
            expenseData["amount"] = expense->getAmount();
            expenseData["date"] = DateUtils::timePointToString(expense->getDate());
            expenseData["description"] = expense->getDescription();

            categoryData["expenses"].push_back(expenseData);
        }

        jsonData["categories"].push_back(categoryData);
    }

    // Save budgets
    for (const auto &budget : user->getBudgets())
    {
        json budgetData;
        budgetData["id"] = budget.getID();
        budgetData["name"] = budget.getName();
        budgetData["amount"] = budget.getBudgetAmount();
        budgetData["spent_amount"] = budget.getSpentAmount();
        budgetData["start_date"] = DateUtils::timePointToString(budget.getStartDate());
        budgetData["end_date"] = DateUtils::timePointToString(budget.getEndDate());
        budgetData["source"] = budget.getSourceDetails();

        jsonData["budgets"].push_back(budgetData);
    }

    outFile << jsonData.dump(4);
    std::cout << "Data saved successfully to user_data.json.\n";
}

bool FileManager::loadDataFromFile()
{
    try
    {
        std::ifstream inFile(fileName);
        if (!inFile.is_open())
        {
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

        for (const auto &categoryData : jsonData["categories"])
        {
            Category category(categoryData["name"].get<std::string>());
            cout << "Category: " << category.getCategoryName() << endl;

            if (!categoryData.contains("expenses"))
            {
                user.addCategory(category);
                continue;
            }

            for (const auto &expenseData : categoryData["expenses"])
            {
                cout << "There is an expense" << endl;
                int expenseId = expenseData["id"].get<int>();
                double amount = expenseData["amount"].get<double>();
                auto date = DateUtils::stringToTimePoint(expenseData["date"].get<std::string>());
                std::string description = expenseData["description"].get<std::string>();

                cout << "Expense ID: " << expenseId << ", Amount: " << amount << ", Date: " << DateUtils::timePointToString(date) << ", Description: " << description << endl;

                Expense *expense = new Expense(expenseId, amount, date, description, &category);
                category.addExpense(expense);
            }
            cout << "Category expenses: " << category.getExpenseCount() << endl;

            user.addCategory(category);
        }

        cout << "Total categories: " << user.getCategories().size() << endl;

        // Load budgets
        if (!jsonData["budgets"].empty())
        {
            if (jsonData.contains("budgets"))
            {
                for (const auto &budgetData : jsonData["budgets"])
                {
                    cout << "There is a budget" << endl;
                    int budgetId = budgetData["id"].get<int>();
                    string name = budgetData["name"].get<std::string>();
                    double amount = budgetData["amount"].get<double>();
                    double spentAmount = budgetData["spent_amount"].get<double>();
                    auto startDate = DateUtils::stringToTimePoint(budgetData["start_date"].get<std::string>());
                    auto endDate = DateUtils::stringToTimePoint(budgetData["end_date"].get<std::string>());
                    string source = budgetData["source"].get<std::string>();

                    Budget budget(budgetId, name, amount, spentAmount, startDate, endDate, source);
                    user.addBudget(budget);
                }
                cout << "Total budgets: " << user.getBudgetCount() << endl;
            }
        }

        main_user = user;
        std::cout << "Data loaded successfully from user_data.json.\n";
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool FileManager::fileExists()
{
    std::ifstream file(fileName);
    return file.good();
}

void FileManager::deleteAllUser()
{
    std::ofstream outFile(fileName);
    if (!outFile.is_open())
    {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    // Write an empty JSON array to the file
    outFile << "[]";
    outFile.close();
    std::cout << "All user data deleted successfully.\n";
}

void FileManager::deleteUser(const std::string &username)
{
    std::ifstream inFile(fileName);
    if (!inFile.is_open())
    {
        std::cerr << "Failed to open file for reading.\n";
        return;
    }

    json jsonData;
    inFile >> jsonData;
    inFile.close();

    // Remove the user with the specified username
    jsonData.erase(std::remove_if(jsonData.begin(), jsonData.end(),
                                  [&username](const json &user)
                                  {
                                      return user["username"].get<std::string>() == username;
                                  }),
                   jsonData.end());

    // Write the updated data back to the file
    std::ofstream outFile(fileName);
    if (!outFile.is_open())
    {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    outFile << jsonData.dump(4);
    outFile.close();
}

bool FileManager::doesUserExist(const std::string &username)
{
    std::ifstream inFile(fileName);
    if (!inFile.is_open())
    {
        std::cerr << "Failed to open file for reading.\n";
        return false;
    }

    json jsonData;
    inFile >> jsonData;

    if (jsonData["username"].get<std::string>() == username)
    {
        cout << "User exists" << endl;
        return true;
    }

    return false;
}

User &FileManager::getMainUser()
{
    return main_user;
}

void FileManager::setMainUser(const User &user)
{
    main_user = user;
}

string FileManager::getMainUserPawword()
{
    try
    {
        std::ifstream inFile(fileName);
        if (!inFile.is_open())
        {
            std::cerr << "Failed to open file for reading.\n";
            return "";
        }

        json jsonData;
        inFile >> jsonData;

        return jsonData["password"].get<std::string>();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
