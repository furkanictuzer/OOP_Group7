/**
 * @file UiRegisterWindow.h
 * @brief Contains the implementation of the UiRegisterWindow class.
 */

#include "AuthenticationManager.h"
#include <iostream>

/**
 * @class UiRegisterWindow
 * @brief A class representing the registration window where users can create an account.
 * 
 * This class manages the user interface for registering a new user, including fields for 
 * entering a username and password, as well as buttons to register or navigate to the login page.
 */
class UiRegisterWindow : public Fl_Window {
private:
    Fl_Input* username_input; ///< Input field for the username.
    Fl_Input* password_input; ///< Input field for the password.
    Fl_Button* register_button; ///< Button for submitting the registration.
    Fl_Button* login_button; ///< Button for navigating to the login window.
    AuthenticationManager* authenticationManager; ///< Authentication manager used to handle registration.

public:
    /**
     * @brief Constructor that initializes the UiRegisterWindow and its UI components.
     * 
     * @param width The width of the window.
     * @param height The height of the window.
     * @param authenticationManager The authentication manager instance.
     */
    UiRegisterWindow(int width, int height, AuthenticationManager* authenticationManager);

    /**
     * @brief Destructor that cleans up UI components.
     */
    ~UiRegisterWindow();

    /**
     * @brief Callback function for the register button. 
     * Validates input and attempts to register a new user.
     * If registration succeeds, the login window is shown.
     * 
     * @param widget The widget that triggered the callback.
     * @param data The user data passed to the callback (in this case, the current window).
     */
    static void register_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function for the login button. Navigates to the login window.
     * 
     * @param widget The widget that triggered the callback.
     * @param data The user data passed to the callback (in this case, the current window).
     */
    static void login_callback(Fl_Widget* widget, void* data);
};
