#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include "FileManager.h"
#include "UiExpenseWindow.h"
#include "UiCategoryWindow.h"

class UiMainWindow : public Fl_Window {
private:
    Fl_Button* expenses_button;
    Fl_Button* set_budget_button;
    Fl_Button* my_categories_button;
    Fl_Button* get_report_button;
    Fl_Button* recent_payments_button;

    static void button_callback(Fl_Widget* widget, void* data);

public:
    UiMainWindow(int width, int height);
    void navigateToExpense();
    void navigateToBudget();
    void navigateToCategories();
    void navigateToReport();
    void navigateToPayments();
};

#endif // UI_MAIN_WINDOW_H