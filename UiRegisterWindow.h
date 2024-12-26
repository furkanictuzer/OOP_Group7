#ifndef UI_REGISTER_WINDOW_H
#define UI_REGISTER_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>

#include <string>
#include <iostream>
#include "FileManager.h"
#include "UiLoginWindow.h"
#include "AuthenticationManager.h"

/**
 * @class UiRegisterWindow
 * @brief A window for user registration.
 * 
 * This class represents the window where users can register by entering their
 * username and password. It provides options for both registration and navigating
 * to the login window.
 */
class UiRegisterWindow : public Fl_Window {
private:
    Fl_Input* username_input; ///< Input field for entering the username.
    Fl_Input* password_input; ///< Input field for entering the password.

    Fl_Button* register_button; ///< Button for submitting the registration form.
    Fl_Button* login_button; ///< Button for navigating to the login window.

    AuthenticationManager* authenticationManager; ///< Manager responsible for user authentication.

    /**
     * @brief Callback function for registering a new user.
     * 
     * This function is triggered when the "Register" button is clicked. It handles
     * the registration process, validating the input and creating a new user account.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void register_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function for navigating to the login window.
     * 
     * This function is triggered when the "Login" button is clicked. It navigates
     * the user to the login window.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void login_callback(Fl_Widget* widget, void* data);

public:
    /**
     * @brief Constructs the registration window.
     * 
     * Initializes the registration window with input fields for the username and
     * password, as well as buttons for registration and navigation to the login window.
     * 
     * @param width The width of the window.
     * @param height The height of the window.
     * @param authenticationManager The authentication manager for handling the user registration process.
     */
    UiRegisterWindow(int width, int height, AuthenticationManager* authenticationManager);

    /**
     * @brief Destructor for cleaning up resources.
     */
    ~UiRegisterWindow();
};

#endif // UI_REGISTER_WINDOW_H
