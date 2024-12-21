#ifndef UI_MANAGER_WINDOW_H
#define UI_MANAGER_WINDOW_H

/*#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>*/

#include <string>

class UiMainWindow
{

public:
    UiMainWindow(int height, int width, std::string name);
    void navigateToExpense();
    void navigateToProfile();
    void navigateToReport();
};

#endif