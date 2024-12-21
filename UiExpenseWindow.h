#ifndef UI_EXPENSE_WINDOW_H
#define UI_EXPENSE_WINDOW_H

#include <string>

class UiExpenseWindow
{
private:
    /* Fl_Input expenseAmount;
       Fl_Choice categoryChoice;
       Fl_Button submitButton;
     */
public:
    UiExpenseWindow(int height, int width, std::string name);
    void navigateToMain();
    void navigateToProfile();
};

#endif
