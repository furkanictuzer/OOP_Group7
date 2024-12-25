#ifndef UI_ADD_EXPENSE_WINDOW_H
#define UI_ADD_EXPENSE_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Check_Button.H>
#include <FL/fl_ask.H>

#include <iostream>
#include <string>
#include <vector>

#include "Category.h"
#include "DateUtils.h"
#include "ExpenseManager.h"
#include "FileManager.h"
#include "MockClock.h"
#include "UiMainWindow.h"
#include "DateUtils.h"
#include "ExpenseManager.h"
#include "FileManager.h"

class UiAddExpenseWindow : public Fl_Window {
private:
    Fl_Input* amount_input;
    Fl_Choice* category_choice;
    Fl_Choice* day_choice;
    Fl_Choice* month_choice;
    Fl_Choice* year_choice;
    Fl_Multiline_Input* description_input;
    Fl_Check_Button* repeated_expense_check;
    Fl_Button* save_button;
    Fl_Button* cancel_button;

    static void save_callback(Fl_Widget* widget, void* data);
    static void cancel_callback(Fl_Widget* widget, void* data);

    void populateDateChoices();

public:
    UiAddExpenseWindow(int width, int height);
    ~UiAddExpenseWindow();
};

#endif // UI_EXPENSE_WINDOW_H
