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

class UiRegisterWindow : public Fl_Window {
private:
    Fl_Input* username_input;
    Fl_Input* password_input;

    Fl_Button* register_button;
    Fl_Button* login_button;

    AuthenticationManager* authenticationManager;

    static void register_callback(Fl_Widget* widget, void* data);
    static void login_callback(Fl_Widget* widget, void* data);

public:
    UiRegisterWindow(int width, int height, AuthenticationManager* authenticationManager);
    ~UiRegisterWindow();
};

#endif // UI_REGISTER_WINDOW_H