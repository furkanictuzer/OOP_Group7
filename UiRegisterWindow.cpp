#include "UiRegisterWindow.h"
#include <iostream>

UiRegisterWindow::UiRegisterWindow(int width, int height,  AuthenticationManager* authenticationManager)
    : Fl_Window(width, height, "Register Window"), authenticationManager(authenticationManager) 
    {
    username_input = new Fl_Input(100, 50, 150, 30, "Username:");
    password_input = new Fl_Input(100, 100, 150, 30, "Password:");
    password_input->type(FL_SECRET_INPUT); // Hide password input
    

    register_button = new Fl_Button(100, 150, 150, 30, "Register");
    register_button->callback(register_callback, (void*)this);

    login_button = new Fl_Button(100, 200, 250, 30, "Already have an account? Login");
    login_button->callback(login_callback, (void*)this);

    end();
}

UiRegisterWindow::~UiRegisterWindow() {
    delete username_input;
    delete password_input;
    delete register_button;
    delete login_button;
}

void UiRegisterWindow::register_callback(Fl_Widget* widget, void* data) {
    UiRegisterWindow* window = (UiRegisterWindow*)data;

    std::string username = window->username_input->value();
    std::string password = window->password_input->value();

    if (!username.empty() && !password.empty()) {
        if (window->authenticationManager->tryToRegister(username, password))
        {
            window->hide();

            // Create and show the login window
            UiLoginWindow* login_window = new UiLoginWindow(window->w(), window->h(), window->authenticationManager);
            login_window->show();
        }
        else
        {
            fl_message("Registration failed!");
        }
        
    } else {
        fl_message("Please enter a username and password.");
    }
}

void UiRegisterWindow::login_callback(Fl_Widget* widget, void* data) {
    UiRegisterWindow* window = (UiRegisterWindow*)data;
    window->hide(); // Hide the registration window

    // Create and show the login window
    UiLoginWindow* login_window = new UiLoginWindow(window->w(), window->h(), window->authenticationManager);
    login_window->show();
}