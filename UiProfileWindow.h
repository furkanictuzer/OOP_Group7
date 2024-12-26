#ifndef UI_PROFILE_WINDOW_H
#define UI_PROFILE_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <string>
#include "User.h"

/**
 * @class UiProfileWindow
 * @brief A window for managing user profile.
 * 
 * This class represents a window that allows users to manage their profile.
 * It provides options to change the username, change the password, delete the account,
 * and navigate back to the main window. It also updates the displayed username
 * after changes.
 */
class UiProfileWindow : public Fl_Window {
private:
    Fl_Box* usernameBox; ///< Box displaying the current username.
    Fl_Input* newUsernameInput; ///< Input field for entering a new username.
    Fl_Input* passwordInput; ///< Input field for entering the password.
    Fl_Button* renameButton; ///< Button for renaming the username.
    Fl_Button* changePasswordButton; ///< Button for changing the password.
    Fl_Button* deleteAccountButton; ///< Button for deleting the account.
    Fl_Button* backButton; ///< Button for navigating back to the previous window.

    /**
     * @brief Callback function for renaming the user.
     * 
     * This function is triggered when the "Rename" button is clicked. It handles
     * the process of changing the username of the user.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void rename_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function for changing the user's password.
     * 
     * This function is triggered when the "Change Password" button is clicked.
     * It allows the user to change their account password.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void change_password_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function for deleting the user account.
     * 
     * This function is triggered when the "Delete Account" button is clicked. It
     * deletes the user account and removes the associated data.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void delete_account_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function for navigating back to the previous window.
     * 
     * This function is triggered when the "Back" button is clicked, returning the
     * user to the main window.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void back_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Updates the visual representation of the username.
     * 
     * This function updates the displayed username in the window after a change.
     */
    void updateUsernameVisual();

    /**
     * @brief Navigates to the main window.
     * 
     * This function takes the user back to the main window.
     */
    void navigateToMain();

public:
    /**
     * @brief Constructs the profile window.
     * 
     * Initializes the profile window with appropriate widgets for managing the user's
     * profile, such as username, password, and account settings.
     * 
     * @param width The width of the window.
     * @param height The height of the window.
     */
    UiProfileWindow(int width, int height);

    /**
     * @brief Destructor for cleaning up resources.
     */
    ~UiProfileWindow();
};

#endif // UI_PROFILE_WINDOW_H
