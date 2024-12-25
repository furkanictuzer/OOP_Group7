#ifndef UI_BUDGET_WINDOW_H
#define UI_BUDGET_WINDOW_H

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
#include "UiAddBudgetWindow.h"

class UiBudgetWindow : public Fl_Window
{
private:
    Fl_Browser* budgetBrowser;
    Fl_Button* newBudgetButton;
    Fl_Button* closeButton;

    static void close_callback(Fl_Widget* widget, void* data);
    static void new_budget_callback(Fl_Widget* widget, void* data);

    void populateBudgets();

public:
    UiBudgetWindow(int width, int height);
    ~UiBudgetWindow();

};

#endif //!UI_BUDGET_WINDOW_H