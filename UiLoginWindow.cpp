#include "UiLoginWindow.h"
#include <iostream>

/**
 * @class UiLoginWindow
 * @brief A window for logging in users.
 * 
 * This class provides the login functionality for the application. Users can input their username 
 * and password to authenticate themselves using the provided AuthenticationManager.
 */
UiLoginWindow::UiLoginWindow(int width, int height, AuthenticationManager* authenticationManager)
    : Fl_Window(width, height, "Login Window"), authenticationManager(authenticationManager) {
    // Create the input fields for username and password
    username_input = new Fl_Input(100, 50, 150, 30, "Username:");
    password_input = new Fl_Input(100, 100, 150, 30, "Password:");
    password_input->type(FL_SECRET_INPUT); // Hide password input

    // Create the buttons for login and registration
    login_button = new Fl_Button(100, 150, 150, 30, "Login");
    register_button = new Fl_Button(100, 200, 250, 30, "Don't have an account? Register");

    // Set callback functions for the buttons
    login_button->callback(login_callback, (void*)this);
    register_button->callback(register_callback, (void*)this);

    // Finalize window setup
    end();
}

/**
 * @brief Destructor for UiLoginWindow.
 * 
 * This destructor cleans up the allocated resources for the login window.
 */
UiLoginWindow::~UiLoginWindow() {
    delete username_input;
    delete password_input;
    delete login_button;
    delete register_button;
}

/**
 * @brief Callback function for the login button.
 * 
 * This function is triggered when the "Login" button is clicked. It attempts to authenticate the user 
 * by calling the tryToLogin method of the AuthenticationManager. If successful, it transitions to the main window.
 * If authentication fails, an error message is displayed.
 * 
 * @param widget The widget that triggered the callback.
 * @param data The window data.
 */
void UiLoginWindow::login_callback(Fl_Widget* widget, void* data) {
    UiLoginWindow* window = (UiLoginWindow*)data;
    std::string username = window->username_input->value();
    std::string password = window->password_input->value();

    // Attempt login with the entered credentials
    if (window->authenticationManager->tryToLogin(username, password)) {
        window->hide();

        // Create and show the main window upon successful login
        UiMainWindow* main_window = new UiMainWindow(window->w(), window->h());
        main_window->show();
    } else {
        // Show error message on invalid login
        fl_message("Invalid username or password.");
    }
}

/**
 * @brief Callback function for the registration button.
 * 
 * This function is triggered when the "Don't have an account? Register" button is clicked. It hides the 
 * login window and shows the registration window, allowing the user to create a new account.
 * 
 * @param widget The widget that triggered the callback.
 * @param data The window data.
 */
void UiLoginWindow::register_callback(Fl_Widget* widget, void* data) {
    UiLoginWindow* window = (UiLoginWindow*)data;
    window->hide();

    // Create and show the registration window
    UiRegisterWindow* register_window = new UiRegisterWindow(window->w(), window->h(), window->authenticationManager);
    register_window->show();
}
