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

const std::string FileManager::fileName = "user_data.json"; ///< The filename for storing user data
User FileManager::main_user(0, "", "", 0); ///< The main user object

/**
 * @brief Saves the user data to a file.
 * 
 * This function writes the user information, including categories, expenses, and budgets, to a JSON file.
 * 
 * @param user A pointer to the User object whose data will be saved.
 */
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

    // Save categories and their expenses
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

    outFile << jsonData.dump(4); ///< Write the formatted JSON data to the file
    std::cout << "Data saved successfully to user_data.json.\n";
}

/**
 * @brief Loads the user data from a file.
 * 
 * This function reads the user data, including categories, expenses, and budgets, from a JSON file and loads it into the main user object.
 * 
 * @return true If data is successfully loaded from the file.
 * @return false If there is an error loading the data.
 */
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

        // Load categories and their expenses
        for (const auto &categoryData : jsonData["categories"])
        {
            Category category(categoryData["name"].get<std::string>());
            std::cout << "Category: " << category.getCategoryName() << std::endl;

            if (!categoryData.contains("expenses"))
            {
                user.addCategory(category);
                continue;
            }

            for (const auto &expenseData : categoryData["expenses"])
            {
                std::cout << "There is an expense" << std::endl;
                int expenseId = expenseData["id"].get<int>();
                double amount = expenseData["amount"].get<double>();
                auto date = DateUtils::stringToTimePoint(expenseData["date"].get<std::string>());
                std::string description = expenseData["description"].get<std::string>();

                std::cout << "Expense ID: " << expenseId << ", Amount: " << amount << ", Date: " << DateUtils::timePointToString(date) << ", Description: " << description << std::endl;

                Expense *expense = new Expense(expenseId, amount, date, description, &category);
                category.addExpense(expense);
            }
            std::cout << "Category expenses: " << category.getExpenseCount() << std::endl;

            user.addCategory(category);
        }

        std::cout << "Total categories: " << user.getCategories().size() << std::endl;

        // Load budgets
        if (!jsonData["budgets"].empty())
        {
            if (jsonData.contains("budgets"))
            {
                for (const auto &budgetData : jsonData["budgets"])
                {
                    std::cout << "There is a budget" << std::endl;
                    int budgetId = budgetData["id"].get<int>();
                    std::string name = budgetData["name"].get<std::string>();
                    double amount = budgetData["amount"].get<double>();
                    double spentAmount = budgetData["spent_amount"].get<double>();
                    auto startDate = DateUtils::stringToTimePoint(budgetData["start_date"].get<std::string>());
                    auto endDate = DateUtils::stringToTimePoint(budgetData["end_date"].get<std::string>());
                    std::string source = budgetData["source"].get<std::string>();

                    Budget budget(budgetId, name, amount, spentAmount, startDate, endDate, source);
                    user.addBudget(budget);
                }
                std::cout << "Total budgets: " << user.getBudgetCount() << std::endl;
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

/**
 * @brief Checks if the file containing user data exists.
 * 
 * This function checks whether the `user_data.json` file exists.
 * 
 * @return true If the file exists.
 * @return false If the file does not exist.
 */
bool FileManager::fileExists()
{
    std::ifstream file(fileName);
    return file.good();
}

/**
 * @brief Deletes all user data from the file.
 * 
 * This function clears the contents of the `user_data.json` file by writing an empty JSON array.
 */
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

/**
 * @brief Deletes a specific user from the file.
 * 
 * This function removes the user with the specified username from the `user_data.json` file.
 * 
 * @param username The username of the user to be deleted.
 */
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

/**
 * @brief Checks if a user exists in the file.
 * 
 * This function checks if the user with the specified username exists in the `user_data.json` file.
 * 
 * @param username The username to check.
 * @return true If the user exists.
 * @return false If the user does not exist.
 */
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
        std::cout << "User exists" << std::endl;
        return true;
    }

    return false;
}

/**
 * @brief Retrieves the main user object.
 * 
 * This function returns the main user object.
 * 
 * @return The main User object.
 */
User &FileManager::getMainUser()
{
    return main_user;
}

/**
 * @brief Sets the main user object.
 * 
 * This function sets the main user object to the specified user.
 * 
 * @param user The User object to be set as the main user.
 */
void FileManager::setMainUser(const User &user)
{
    main_user = user;
}

/**
 * @brief Retrieves the password of the main user.
 * 
 * This function retrieves the password of the main user from the data file.
 * 
 * @return The password of the main user.
 */
std::string FileManager::getMainUserPawword()
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
