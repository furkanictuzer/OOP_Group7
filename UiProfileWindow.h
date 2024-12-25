#ifndef UI_PROFILE_WINDOW_H
#define UI_PROFILE_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <string>
#include "User.h"

class UiProfileWindow : public Fl_Window
{
private:
    Fl_Box* usernameBox;
    Fl_Input* newUsernameInput;
    Fl_Input* passwordInput;
    Fl_Button* renameButton;
    Fl_Button* changePasswordButton;
    Fl_Button* deleteAccountButton;
    Fl_Button* backButton;

    static void rename_callback(Fl_Widget* widget, void* data);
    static void change_password_callback(Fl_Widget* widget, void* data);
    static void delete_account_callback(Fl_Widget* widget, void* data);
    static void back_callback(Fl_Widget* widget, void* data);
    
    void updateUsernameVisual();
    void navigateToMain();

public:
    UiProfileWindow(int width, int height);
    ~UiProfileWindow();

};

#endif // UI_PROFILE_WINDOW_H