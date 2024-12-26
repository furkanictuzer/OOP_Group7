/**
 * @file UiProfileWindow.cpp
 * @brief Implementation of the Profile window UI for modifying user information.
 */

#include "UiProfileWindow.h"
#include "UiRegisterWindow.h"
#include "UiMainWindow.h"
#include "FileManager.h"
#include "AuthenticationManager.h"
#include <iostream>
#include <stdexcept>

/**
 * @class UiProfileWindow
 * @brief This class represents the user profile window, where the user can update their username, password,
 * and delete their account.
 *
 * The class provides functionality for displaying the current username, allowing the user to update their username 
 * and password, or delete the account. It also provides navigation to the main window or registration window.
 */
UiProfileWindow::UiProfileWindow(int width, int height)
    : Fl_Window(width, height, "Profile Window")
{
    User& user = FileManager::getMainUser();

    // Display the current username in a box
    usernameBox = new Fl_Box(120, 50, 200, 30, ("Username: " + user.getUserName()).c_str());

    // Initialize username display update
    this->updateUsernameVisual();

    // Input fields for changing username and password
    newUsernameInput = new Fl_Input(120, 100, 200, 30, "New Username:");
    renameButton = new Fl_Button(120, 150, 200, 30, "Rename Username");
    renameButton->callback(rename_callback, (void*)this);

    passwordInput = new Fl_Input(120, 200, 200, 30, "New Password:");
    passwordInput->type(FL_SECRET_INPUT);

    // Button to change password
    changePasswordButton = new Fl_Button(120, 250, 200, 30, "Change Password");
    changePasswordButton->callback(change_password_callback, (void*)this);

    // Button to delete account
    deleteAccountButton = new Fl_Button(120, 300, 200, 30, "Delete Account");
    deleteAccountButton->callback(delete_account_callback, (void*)this);

    // Button to navigate back to the main window
    backButton = new Fl_Button(120, 350, 200, 30, "Back");
    backButton->callback(back_callback, (void*)this);

    end();
}

/**
 * @brief Destructor to clean up dynamically allocated resources.
 */
UiProfileWindow::~UiProfileWindow()
{
    delete usernameBox;
    delete newUsernameInput;
    delete passwordInput;
    delete renameButton;
    delete changePasswordButton;
    delete deleteAccountButton;
    delete backButton;
}

/**
 * @brief Updates the visual display of the current username.
 *
 * This method fetches the current username from the `FileManager` and updates the label in the profile window.
 */
void UiProfileWindow::updateUsernameVisual()
{
    std::string username = FileManager::getMainUser().getUserName();

    std::string label = "Username: " + username;
    usernameBox->copy_label(label.c_str());
    usernameBox->redraw();
}

/**
 * @brief Navigates back to the main window.
 *
 * This method hides the current profile window and opens the main window.
 */
void UiProfileWindow::navigateToMain()
{
    hide();

    UiMainWindow* mainWindow = new UiMainWindow(w(), h());
    mainWindow->show();
}

/**
 * @brief Callback function for renaming the username.
 *
 * This function checks if the new username is valid, updates the user's username, and saves the new data to a file.
 * A message is shown to indicate whether the change was successful.
 *
 * @param widget The widget that triggered the callback.
 * @param data The data passed to the callback (the current window).
 */
void UiProfileWindow::rename_callback(Fl_Widget* widget, void* data)
{
    UiProfileWindow* window = (UiProfileWindow*)data;
    const char* newUsername = window->newUsernameInput->value();

    if (newUsername && strlen(newUsername) > 0) {
        User& user = FileManager::getMainUser();
        user.setUsername(newUsername);
        FileManager::saveDataToFile(&user);

        window->updateUsernameVisual();

        fl_message("Username updated successfully.");
    } else {
        fl_alert("Please enter a valid username.");
    }
}

/**
 * @brief Callback function for changing the password.
 *
 * This function checks if the new password is valid, updates the user's password, and saves the new data to a file.
 * A message is shown to indicate whether the change was successful.
 *
 * @param widget The widget that triggered the callback.
 * @param data The data passed to the callback (the current window).
 */
void UiProfileWindow::change_password_callback(Fl_Widget* widget, void* data)
{
    UiProfileWindow* window = (UiProfileWindow*)data;
    const char* newPassword = window->passwordInput->value();

    if (newPassword && strlen(newPassword) > 0) {
        User& user = FileManager::getMainUser();
        user.setPassword(newPassword);
        FileManager::saveDataToFile(&user);
        fl_message("Password updated successfully.");
    } else {
        fl_alert("Please enter a valid password.");
    }
}

/**
 * @brief Callback function for deleting the user's account.
 *
 * This function deletes the user's account from the file system and navigates to the registration window.
 *
 * @param widget The widget that triggered the callback.
 * @param data The data passed to the callback (the current window).
 */
void UiProfileWindow::delete_account_callback(Fl_Widget* widget, void* data)
{
    UiProfileWindow* window = (UiProfileWindow*)data;
    User user = FileManager::getMainUser();
    FileManager::deleteAllUser();

    fl_message("Account deleted successfully.");
    window->hide();

    AuthenticationManager authManager;
    UiRegisterWindow* registerWindow = new UiRegisterWindow(window->w(), window->h(), &authManager);
    registerWindow->show();
}

/**
 * @brief Callback function for navigating back to the main window.
 *
 * This function is triggered when the back button is pressed, returning the user to the main window.
 *
 * @param widget The widget that triggered the callback.
 * @param data The data passed to the callback (the current window).
 */
void UiProfileWindow::back_callback(Fl_Widget* widget, void* data)
{
    UiProfileWindow* window = (UiProfileWindow*)data;
    window->navigateToMain();
}
