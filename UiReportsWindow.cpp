#include "UiReportsWindow.h"

UiReportsWindow::UiReportsWindow(int height, int width, std::string name)
    : Fl_Window(width, height, "New Report")
{
    reportTypeChoice = new Fl_Choice(100, 50, 150, 50, "Choose Report Type: ");
    reportTypeChoice->add("Weekly Report");
    reportTypeChoice->add("Monthly Report");
    reportTypeChoice->add("Annual Report");
    reportTypeChoice->add("Specific Report");//There need to be callback func and
    reportTypeChoice->add("Category Report");//another window to specialize reports

    generateButton = new Fl_Button(400, 50, 100, 50, "Generate "); //Another callback for here

    reportDisplayArea = new Fl_Box(100, 300, 300, 300, "Report ");
    end();
}

UiReportsWindow::~UiReportsWindow()
{
    delete reportDisplayArea;
    delete reportTypeChoice;
    delete generateButton;
}