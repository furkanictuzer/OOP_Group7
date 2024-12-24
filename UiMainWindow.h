#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>
#include <string>

class UiMainWindow : public Fl_Window {
private:
    Fl_Button* last_expenses_button;
    Fl_Button* set_budget_button;
    Fl_Button* my_categories_button;
    Fl_Button* get_report_button;
    Fl_Button* recent_payments_button;
    Fl_Button* add_expense_button;

    static void button_callback(Fl_Widget* widget, void* data);

public:
    UiMainWindow(int width, int height, const std::string& name);
    void navigateToLastExpense();
    void navigateToBudget();
    void navigateToCategories();
    void navigateToReport();
    void navigateToPayments();
    void navigateToAddExpense();
};

#endif // UI_MAIN_WINDOW_H