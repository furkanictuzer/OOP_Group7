#ifndef UI_LOGIN_WINDOW_H
#define UI_LOGIN_WINDOW_H

/*#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>*/

#include <string>

class UiLoginWindow
{
private:
    /* Fl_Input loginName;
       Fl_Input loginKey;
       Fl_Button submitButton;
     */
    void controlAndLogin(/*Fl_Input name, Fl_Input key*/);

public:
    UiLoginWindow(int height, int width, std::string name);
};

#endif
