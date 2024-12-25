#ifndef UI_ADD_BUDGET_WINDOW_H
#define UI_ADD_BUDGET_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>

#include <vector>
#include <sstream>

#include "Budget.h"
#include "Expense.h"
#include "Category.h"
#include "FileManager.h"
#include "UiMainWindow.h"
#include "UiAddExpenseWindow.h"
using namespace std;

class UiAddBudgetWindow : public Fl_Window
{
private:
    Fl_Input* nameInput;
    Fl_Choice* dayChoiceStart;
    Fl_Choice* monthChoiceStart;
    Fl_Choice* yearChoiceStart;
    Fl_Choice* dayChoiceEnd;
    Fl_Choice* monthChoiceEnd;
    Fl_Choice* yearChoiceEnd;
    Fl_Input* amountInput;
    Fl_Input* sourceInput;
    Fl_button* cancelButton;
    Fl_Button* addButton;

    static void add_callback(Fl_Widget* widget, void* data);
    static void cancel_callback(Fl_Widget* widget, void* data);

    void populateDateChoices();

public:
    UiAddBudgetWindow(int width, int height);
    ~UiAddBudgetWindow();

}

#endif //!UI_ADD_BUDGET_WINDOW_H