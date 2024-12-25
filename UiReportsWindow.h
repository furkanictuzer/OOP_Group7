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

class UiReportsWindow : public Fl_Window
{
private:
    Fl_Choice* reportTypeChoice;
    Fl_Choice* startDayChoice;
    Fl_Choice* startMonthChoice;
    Fl_Choice* startYearChoice;
    Fl_Choice* endDayChoice;
    Fl_Choice* endMonthChoice;
    Fl_Choice* endYearChoice;
    Fl_Choice* categoryChoice;
    Fl_Button* generateButton;
    Fl_Button* backButton;
    Fl_Browser* reportDisplayArea;
    Fl_Check_Button* createFileCheckButton;

    void populateDateChoices(Fl_Choice* dayChoice, Fl_Choice* monthChoice, Fl_Choice* yearChoice);
    void populateCategoryChoices();
    static void report_type_callback(Fl_Widget* widget, void* data);

public:
    UiReportsWindow(int width, int height);
    ~UiReportsWindow();

    static void back_to_main_callback(Fl_Widget* widget, void* data);
    static void generate_callback(Fl_Widget* widget, void* data);
};

#endif // UI_REPORTS_WINDOW_H
