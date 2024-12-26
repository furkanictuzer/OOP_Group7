#ifndef UI_REPORTS_WINDOW_H
#define UI_REPORTS_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Check_Button.H>
#include <FL/fl_ask.H>

#include <iostream>
#include <stdexcept>
#include <string>

#include "Report.h"
#include "ReportGenerator.h"
#include "DateUtils.h"
#include "FileManager.h"

#include "UiMainWindow.h"

/**
 * @class UiReportsWindow
 * @brief A window for generating and displaying reports.
 * 
 * This class represents the window where users can generate various reports based
 * on selected parameters, such as date range, report type, and category. It also
 * allows the user to save the report as a file if needed.
 */
class UiReportsWindow : public Fl_Window
{
private:
    Fl_Choice* reportTypeChoice; ///< Choice box for selecting the type of report.
    Fl_Choice* startDayChoice; ///< Choice box for selecting the start day of the report.
    Fl_Choice* startMonthChoice; ///< Choice box for selecting the start month of the report.
    Fl_Choice* startYearChoice; ///< Choice box for selecting the start year of the report.
    Fl_Choice* endDayChoice; ///< Choice box for selecting the end day of the report.
    Fl_Choice* endMonthChoice; ///< Choice box for selecting the end month of the report.
    Fl_Choice* endYearChoice; ///< Choice box for selecting the end year of the report.
    Fl_Choice* categoryChoice; ///< Choice box for selecting the category of the report.
    Fl_Button* generateButton; ///< Button for generating the report.
    Fl_Button* backButton; ///< Button for navigating back to the main window.
    Fl_Browser* reportDisplayArea; ///< Display area for showing the generated report.
    Fl_Check_Button* createFileCheckButton; ///< Check button for indicating whether to create a file for the report.

    /**
     * @brief Populates the date choice boxes with valid date values.
     * 
     * This method fills the provided day, month, and year choice boxes with appropriate
     * values, allowing the user to select a valid date range for the report.
     * 
     * @param dayChoice The day choice box to be populated.
     * @param monthChoice The month choice box to be populated.
     * @param yearChoice The year choice box to be populated.
     */
    void populateDateChoices(Fl_Choice* dayChoice, Fl_Choice* monthChoice, Fl_Choice* yearChoice);

    /**
     * @brief Populates the category choice box with available categories.
     * 
     * This method populates the category choice box with available categories that the user
     * can select from when generating a report.
     */
    void populateCategoryChoices();

    /**
     * @brief Callback function for report type selection.
     * 
     * This function is triggered when the user selects a report type. It updates the
     * available options or makes necessary changes in the UI based on the selected report type.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void report_type_callback(Fl_Widget* widget, void* data);

public:
    /**
     * @brief Constructs the reports window.
     * 
     * Initializes the reports window with options for selecting report parameters
     * (date range, report type, category) and buttons for generating the report or
     * returning to the main window.
     * 
     * @param width The width of the window.
     * @param height The height of the window.
     */
    UiReportsWindow(int width, int height);

    /**
     * @brief Destructor for cleaning up resources.
     */
    ~UiReportsWindow();

    /**
     * @brief Callback function for navigating back to the main window.
     * 
     * This function is triggered when the "Back" button is clicked, allowing the user
     * to navigate back to the main window.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void back_to_main_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function for generating a report.
     * 
     * This function is triggered when the "Generate" button is clicked. It handles
     * the generation of the report based on the selected parameters and displays it
     * in the report display area.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void generate_callback(Fl_Widget* widget, void* data);
};

#endif // UI_REPORTS_WINDOW_H
