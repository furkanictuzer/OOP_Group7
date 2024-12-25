#ifndef UI_EXPENSE_WINDOW_H
#define UI_EXPENSE_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>

#include <vector>
#include <sstream>

#include "Expense.h"
#include "Category.h"
#include "FileManager.h"
#include "UiMainWindow.h"
#include "UiAddExpenseWindow.h"

class UiExpenseWindow : public Fl_Window {
private:
    Fl_Browser* expense_browser;
    Fl_Button* close_button;
    Fl_Button* add_expense_button;

    static void close_callback(Fl_Widget* widget, void* data);
    static void add_expense_callback(Fl_Widget* widget, void* data);

    void populateExpenses();

public:
    UiExpenseWindow(int width, int height);
    ~UiExpenseWindow();
};

#endif // UI_EXPENSE_WINDOW_H