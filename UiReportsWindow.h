#ifndef UI_REPORTS_WINDOW_H
#define UI_EXPENSE_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

#include <string>
#include "Report.h"

class UiReportsWindow
{
private:
    Fl_Choice* reportTypeChoice;
    Fl_Button* generateButton;
    Fl_Box* reportDisplayArea;
        
public:
    UiReportsWindow(int height, int width, std::string name);
    void navigateToMain();
    void navigateToProfile();
    ~UiReportsWindow();
};

#endif
