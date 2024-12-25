#include "UiProfileWindow.h"
#include "UiRegisterWindow.h"
#include "UiMainWindow.h"
#include "FileManager.h"
#include "AuthenticationManager.h"
#include <iostream>
#include <stdexcept>

UiProfileWindow::UiProfileWindow(int width, int height)
    : Fl_Window(width, height, "Profile Window")
{
    User& user = FileManager::getMainUser();

    usernameBox = new Fl_Box(120, 50, 200, 30, ("Username: " + user.getUserName()).c_str());

    this->updateUsernameVisual();

    newUsernameInput = new Fl_Input(120, 100, 200, 30, "New Username:");
    renameButton = new Fl_Button(120, 150, 200, 30, "Rename Username");
    renameButton->callback(rename_callback, (void*)this);

    passwordInput = new Fl_Input(120, 200, 200, 30, "New Password:");
    passwordInput->type(FL_SECRET_INPUT);

    changePasswordButton = new Fl_Button(120, 250, 200, 30, "Change Password");
    changePasswordButton->callback(change_password_callback, (void*)this);

    deleteAccountButton = new Fl_Button(120, 300, 200, 30, "Delete Account");
    deleteAccountButton->callback(delete_account_callback, (void*)this);

    backButton = new Fl_Button(120, 350, 200, 30, "Back");
    backButton->callback(back_callback, (void*)this);

    end();
}

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

void UiProfileWindow::updateUsernameVisual()
{
    std::string username = FileManager::getMainUser().getUserName();

    std::string label = "Username: " + username;
    usernameBox->copy_label(label.c_str());
    usernameBox->redraw();
}

void UiProfileWindow::navigateToMain()
{
    hide();

    UiMainWindow* mainWindow = new UiMainWindow(w(), h());
    mainWindow->show();
}

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

void UiProfileWindow::back_callback(Fl_Widget* widget, void* data)
{
    UiProfileWindow* window = (UiProfileWindow*)data;
    window->navigateToMain();
}