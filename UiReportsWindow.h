#ifndef UI_REPORTS_WINDOW_H
#define UI_EXPENSE_WINDOW_H

#include <string>

class UiReportsWindow
{
private:
    /* Fl_Choice reportTypeChoice;
       Fl_Button generateButton;
       Fl_Box reportDisplayArea;
        */
public:
    UiReportsWindow(int height, int width, std::string name);
    void navigateToMain();
    void navigateToProfile();
};

#endif
