#ifndef UI_EXPENSE_WINDOW_H
#define UI_EXPENSE_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>

#include <string>
#include "User.h"

class UiExpenseWindow
{
private:
    Fl_Input* expenseAmount;
    Fl_Choice* categoryChoice;
    Fl_Button* submitButton;

public:
    UiExpenseWindow(int height, int width, std::string name);
    void navigateToMain();
    void navigateToProfile();
    ~UiExpenseWindow();
};

#endif
