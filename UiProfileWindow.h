#ifndef UI_PROFILE_WINDOW_H
#define UI_PROFILE_WINDOW_H

/*#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>*/

#include <string>

class UiProfileWindow
{
private:
    /* Fl_Input incomeAmountField;
       Fl_Input descriptionField;
       Fl_Button submitButton;
    */

public:
    UiProfileWindow(int height, int width, std::string name);
    void navigateToMain();
    void navigateToProfile();
};

#endif