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
#include "Budget.h"
#include <chrono>
#include "ExpenseManager.h"

using json = nlohmann::json;

/**
 * @class FileManager
 * @brief Provides functionality to save, load, and manage user data in a file.
 */
class FileManager {
public:
    /**
     * @brief Saves the user data to a file.
     * 
     * This function serializes the user object and saves it to a file.
     * 
     * @param user A pointer to the User object whose data needs to be saved.
     */
    static void saveDataToFile(const User* user);

    /**
     * @brief Loads user data from a file.
     * 
     * This function deserializes data from the file and loads it into memory.
     * 
     * @return true if the data was successfully loaded, false otherwise.
     */
    static bool loadDataFromFile();

    /**
     * @brief Checks if the data file exists.
     * 
     * @return true if the file exists, false otherwise.
     */
    static bool fileExists();

    /**
     * @brief Checks if a user exists by username.
     * 
     * This function checks if a user with the given username already exists in the file.
     * 
     * @param username The username to check for existence.
     * @return true if the user exists, false otherwise.
     */
    static bool doesUserExist(const std::string& username);

    /**
     * @brief Retrieves the main user.
     * 
     * @return A reference to the main User object.
     */
    static User& getMainUser();

    /**
     * @brief Retrieves the main user's password.
     * 
     * @return The main user's password as a string.
     */
    static string getMainUserPawword();

    /**
     * @brief Sets the main user.
     * 
     * This function sets the provided User object as the main user.
     * 
     * @param user The User object to set as the main user.
     */
    static void setMainUser(const User& user);

    /**
     * @brief Deletes a user by username.
     * 
     * This function deletes the user with the specified username from the data file.
     * 
     * @param username The username of the user to delete.
     */
    static void deleteUser(const std::string& username);

    /**
     * @brief Deletes all users.
     * 
     * This function deletes all user data from the file.
     */
    static void deleteAllUser();

private:
    static User main_user; ///< The main user of the application.
    static const std::string fileName; ///< The name of the file where data is stored.
};

#endif // FILE_MANAGER_H
