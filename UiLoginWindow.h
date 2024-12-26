#ifndef UI_LOGIN_WINDOW_H
#define UI_LOGIN_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>

#include <string>
#include <iostream>
#include "FileManager.h"
#include "UiRegisterWindow.h"
#include "UiMainWindow.h"
#include "AuthenticationManager.h"

/**
 * @class UiLoginWindow
 * @brief A window for user login functionality.
 * 
 * This class provides the user interface for logging in. It includes text
 * input fields for the username and password, as well as buttons for
 * submitting the login information and navigating to the registration window.
 * The class interacts with the AuthenticationManager to validate the login credentials.
 */
class UiLoginWindow : public Fl_Window {
private:
    Fl_Input* username_input; ///< Input field for entering the username.
    Fl_Input* password_input; ///< Input field for entering the password.
    Fl_Button* login_button; ///< Button to submit the login form.
    Fl_Button* register_button; ///< Button to navigate to the registration window.

    AuthenticationManager* authenticationManager; ///< Manages the authentication process.

    /**
     * @brief Callback function for handling the login action.
     * 
     * This function is triggered when the "Login" button is clicked. It validates
     * the credentials entered by the user through the AuthenticationManager.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void login_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function for navigating to the registration window.
     * 
     * This function is triggered when the "Register" button is clicked. It opens
     * the registration window where the user can create a new account.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void register_callback(Fl_Widget* widget, void* data);

public:
    /**
     * @brief Constructs the login window.
     * 
     * Initializes the login window with appropriate size and sets up the
     * widgets for entering credentials and navigating to the registration window.
     * 
     * @param width The width of the window.
     * @param height The height of the window.
     * @param authenticationManager The manager responsible for authentication.
     */
    UiLoginWindow(int width, int height, AuthenticationManager* authenticationManager);

    /**
     * @brief Destructor for cleaning up resources.
     */
    ~UiLoginWindow();
};

#endif // UI_LOGIN_WINDOW_H
