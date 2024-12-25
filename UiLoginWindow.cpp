#include "UiLoginWindow.h"
#include <iostream>

UiLoginWindow::UiLoginWindow(int width, int height, AuthenticationManager* authenticationManager)
    : Fl_Window(width, height, "Login Window"), authenticationManager(authenticationManager) {
    username_input = new Fl_Input(100, 50, 150, 30, "Username:");
    password_input = new Fl_Input(100, 100, 150, 30, "Password:");
    password_input->type(FL_SECRET_INPUT); // Hide password input

    login_button = new Fl_Button(100, 150, 150, 30, "Login");
    register_button = new Fl_Button(25, 200, 250, 30, "Don't have an account? Register");

    login_button->callback(login_callback, (void*)this);
    register_button->callback(register_callback, (void*)this);

    end();
}

UiLoginWindow::~UiLoginWindow() {
    delete username_input;
    delete password_input;
    delete login_button;
    delete register_button;
}

void UiLoginWindow::login_callback(Fl_Widget* widget, void* data) {
    UiLoginWindow* window = (UiLoginWindow*)data;
    std::string username = window->username_input->value();
    std::string password = window->password_input->value();

    if (window->authenticationManager->tryToLogin(username, password)) {
        
        window->hide();

        UiMainWindow* main_window = new UiMainWindow(window->w(), window->h());
        main_window->show();
    } else {
        fl_message("Invalid username or password.");
    }
}

void UiLoginWindow::register_callback(Fl_Widget* widget, void* data) {
    UiLoginWindow* window = (UiLoginWindow*)data;
    window->hide();

    UiRegisterWindow* register_window = new UiRegisterWindow(window->w(), window->h(), window->authenticationManager);
    register_window->show();
}