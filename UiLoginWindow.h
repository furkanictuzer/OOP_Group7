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

class UiLoginWindow : public Fl_Window {
private:
    Fl_Input* username_input;
    Fl_Input* password_input;
    Fl_Button* login_button;
    Fl_Button* register_button;

    AuthenticationManager* authenticationManager;

    static void login_callback(Fl_Widget* widget, void* data);
    static void register_callback(Fl_Widget* widget, void* data);

public:
    UiLoginWindow(int width, int height, AuthenticationManager* authenticationManager);
    ~UiLoginWindow();
};

#endif // UI_LOGIN_WINDOW_H