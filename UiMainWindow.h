#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>          
#include "FileManager.h"
#include "UiExpenseWindow.h"
#include "UiCategoryWindow.h"
#include "UiBudgetWindow.h"
#include "UiReportsWindow.h"
#include "UiProfileWindow.h"
#include "NotificationManager.h"
#include "MockClock.h"         

/**
 * @class UiMainWindow
 * @brief Represents the main window of the application.
 * 
 * This class is responsible for displaying the main window of the application. It includes various buttons
 * to navigate to different sections such as Expenses, Budget, Categories, Reports, and Profile.
 */
class UiMainWindow : public Fl_Window {
private:
    /** Box displaying the current date. */
    Fl_Box* date_display;

    /** Button to navigate to the Expenses section. */
    Fl_Button* expenses_button;

    /** Button to navigate to the Budget section. */
    Fl_Button* set_budget_button;

    /** Button to navigate to the Categories section. */
    Fl_Button* my_categories_button;

    /** Button to navigate to the Reports section. */
    Fl_Button* get_report_button;

    /** Button to navigate to the Profile section. */
    Fl_Button* profile_button;

    /**
     * @brief Callback function for handling button clicks.
     * 
     * This function is triggered when any of the buttons in the main window are clicked.
     * 
     * @param widget The widget that triggered the callback.
     * @param data A pointer to additional data (not used in this case).
     */
    static void button_callback(Fl_Widget* widget, void* data);

public:
    /**
     * @brief Constructor to create the main window.
     * 
     * This constructor initializes the UI elements of the main window, including buttons and the date display.
     * It sets up the layout and makes the window ready for interaction.
     * 
     * @param width The width of the window.
     * @param height The height of the window.
     */
    UiMainWindow(int width, int height);

    /**
     * @brief Destructor to clean up resources.
     * 
     * This destructor ensures proper cleanup of any dynamically allocated resources when the window is closed.
     */
    ~UiMainWindow();

    /**
     * @brief Navigates to the Expenses window.
     * 
     * This function opens the Expense window when the corresponding button is clicked.
     */
    void navigateToExpense();

    /**
     * @brief Navigates to the Budget window.
     * 
     * This function opens the Budget window when the corresponding button is clicked.
     */
    void navigateToBudget();

    /**
     * @brief Navigates to the Categories window.
     * 
     * This function opens the Categories window when the corresponding button is clicked.
     */
    void navigateToCategories();

    /**
     * @brief Navigates to the Reports window.
     * 
     * This function opens the Reports window when the corresponding button is clicked.
     */
    void navigateToReport();

    /**
     * @brief Navigates to the Profile window.
     * 
     * This function opens the Profile window when the corresponding button is clicked.
     */
    void navigateToProfile();
};

#endif // UI_MAIN_WINDOW_H
