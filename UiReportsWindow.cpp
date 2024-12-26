/**
 * @file UiReportsWindow.cpp
 * @brief Implementation of the UiReportsWindow class for generating various reports.
 *
 * This file contains the implementation of the user interface for generating reports, such as
 * weekly, monthly, annual, specific, and category reports. It provides functionality for selecting
 * report type, start and end dates, categories, and creating report files.
 */

#include "UiReportsWindow.h"

/**
 * @brief Constructor for the UiReportsWindow class.
 *
 * This constructor sets up the user interface elements such as choice widgets for selecting
 * report type, start and end dates, categories, and buttons for generating reports and
 * navigating back to the main window.
 *
 * @param width The width of the window.
 * @param height The height of the window.
 */
UiReportsWindow::UiReportsWindow(int width, int height)
    : Fl_Window(width, height, "Reports Window")
{
    // Initialize widgets for report selection
    reportTypeChoice = new Fl_Choice(150, 50, 150, 30, "Choose Report Type: ");
    reportTypeChoice->add("Weekly Report");
    reportTypeChoice->add("Monthly Report");
    reportTypeChoice->add("Annual Report");
    reportTypeChoice->add("Specific Report");
    reportTypeChoice->add("Category Report");
    reportTypeChoice->callback(report_type_callback, (void *)this);

    // Initialize date choice widgets for start and end dates
    startDayChoice = new Fl_Choice(100, 100, 50, 30, "Start Day:");
    startMonthChoice = new Fl_Choice(250, 100, 100, 30, "Start Month:");
    startYearChoice = new Fl_Choice(450, 100, 70, 30, "Start Year:");

    endDayChoice = new Fl_Choice(100, 150, 50, 30, "End Day:");
    endMonthChoice = new Fl_Choice(250, 150, 100, 30, "End Month:");
    endYearChoice = new Fl_Choice(450, 150, 70, 30, "End Year:");

    // Populate date selections for start and end dates
    populateDateChoices(startDayChoice, startMonthChoice, startYearChoice);
    populateDateChoices(endDayChoice, endMonthChoice, endYearChoice);

    // Category selection choice, initially hidden
    categoryChoice = new Fl_Choice(100, 200, 200, 30, "Category:");
    populateCategoryChoices();
    categoryChoice->hide();

    // Create File checkbox
    createFileCheckButton = new Fl_Check_Button(300, 200, 200, 30, "Create File");

    // Back and Generate buttons with callbacks
    backButton = new Fl_Button(550, 40, 50, 50, "Back");
    backButton->callback(back_to_main_callback, (void *)this);

    generateButton = new Fl_Button(400, 40, 100, 50, "Generate");
    generateButton->callback(generate_callback, (void *)this);

    // Browser widget to display generated report
    reportDisplayArea = new Fl_Browser(100, 250, 600, 200);
    end();
}

/**
 * @brief Populates the date choice widgets (day, month, year) with appropriate values.
 *
 * @param dayChoice Pointer to the Fl_Choice widget for the day selection.
 * @param monthChoice Pointer to the Fl_Choice widget for the month selection.
 * @param yearChoice Pointer to the Fl_Choice widget for the year selection.
 */
void UiReportsWindow::populateDateChoices(Fl_Choice *dayChoice, Fl_Choice *monthChoice, Fl_Choice *yearChoice)
{
    for (int i = 1; i <= 31; ++i)
    {
        dayChoice->add(std::to_string(i).c_str());
    }

    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    for (const char *month : months)
    {
        monthChoice->add(month);
    }

    for (int i = 2020; i <= 2030; ++i)
    {
        yearChoice->add(std::to_string(i).c_str());
    }
}

/**
 * @brief Populates the category choices based on the available categories for the user.
 */
void UiReportsWindow::populateCategoryChoices()
{
    User &user = FileManager::getMainUser();
    const std::vector<Category> &categories = user.getCategories();

    for (const auto &category : categories)
    {
        categoryChoice->add((category.getCategoryName()).c_str());
    }
}

/**
 * @brief Callback function for the 'Back' button. Hides the current window and shows the main window.
 *
 * @param widget The Fl_Widget object that triggered the callback.
 * @param data User data (pointer to the UiReportsWindow instance).
 */
void UiReportsWindow::back_to_main_callback(Fl_Widget *widget, void *data)
{
    UiReportsWindow *reports_window = (UiReportsWindow *)data;
    reports_window->hide();

    UiMainWindow *main_window = new UiMainWindow(reports_window->w(), reports_window->h());
    main_window->show();
}

/**
 * @brief Callback function for the 'Generate' button. Generates a report based on user input and displays it.
 *
 * @param widget The Fl_Widget object that triggered the callback.
 * @param data User data (pointer to the UiReportsWindow instance).
 */
void UiReportsWindow::generate_callback(Fl_Widget *widget, void *data)
{
    try
    {
        UiReportsWindow *reports_window = (UiReportsWindow *)data;
        int reportType = reports_window->reportTypeChoice->value();

        // Get the selected start date
        const char *startDayPtr = reports_window->startDayChoice->text();
        const char *startMonthPtr = reports_window->startMonthChoice->text();
        const char *startYearPtr = reports_window->startYearChoice->text();

        if (!startDayPtr || !startMonthPtr || !startYearPtr)
        {
            throw std::runtime_error("Start date selection is incomplete.");
        }

        std::string startDay = startDayPtr;
        std::string startMonth = startMonthPtr;
        std::string startYear = startYearPtr;
        std::string startDateStr = startYear + "-" + startMonth + "-" + startDay + " 00:00:00";

        std::ostringstream startDateStream;
        startDateStream << startYear << "-"
                        << std::setw(2) << std::setfill('0') << (reports_window->startMonthChoice->value() + 1) << "-"
                        << std::setw(2) << std::setfill('0') << std::stoi(startDay) << " 00:00:00";
        std::string start = startDateStream.str();

        auto startDate = DateUtils::stringToTimePoint(start);

        // Variables for end date
        std::string endDay, endMonth, endYear, endDateStr;
        std::chrono::system_clock::time_point endDate;

        // Variables for category
        std::string categoryName;
        const Category *category = nullptr;

        // Check for specific report and category report
        if (reportType == 3 || reportType == 4)
        {
            const char *endDayPtr = reports_window->endDayChoice->text();
            const char *endMonthPtr = reports_window->endMonthChoice->text();
            const char *endYearPtr = reports_window->endYearChoice->text();

            if (!endDayPtr || !endMonthPtr || !endYearPtr)
            {
                throw std::runtime_error("End date selection is incomplete.");
            }

            endDay = endDayPtr;
            endMonth = endMonthPtr;
            endYear = endYearPtr;
            endDateStr = endYear + "-" + endMonth + "-" + endDay + " 23:59:59";

            std::ostringstream endDateStream;
            endDateStream << endYear << "-"
                          << std::setw(2) << std::setfill('0') << (reports_window->endMonthChoice->value() + 1) << "-"
                          << std::setw(2) << std::setfill('0') << std::stoi(endDay) << " 23:59:59";
            std::string end = endDateStream.str();

            endDate = DateUtils::stringToTimePoint(end);

            if (reportType == 4)
            { // Category Report
                categoryName = reports_window->categoryChoice->text();
                if (categoryName.empty())
                {
                    throw std::runtime_error("Category selection is incomplete.");
                }
                User &user = FileManager::getMainUser();
                category = user.getCategoryByName(categoryName);
                if (!category)
                {
                    throw std::runtime_error("Selected category not found.");
                }
            }
        }

        // Example of generating a report based on the selected type
        Report report;
        User &user = FileManager::getMainUser();

        switch (reportType)
        {
        case 0: // Weekly Report
            report = ReportGenerator::generateWeeklyReport(startDate);
            break;
        case 1: // Monthly Report
            report = ReportGenerator::generateMonthlyReport(startDate);
            break;
        case 2: // Annual Report
            report = ReportGenerator::generateAnnualReport(startDate);
            break;
        case 3: // Specific Report
            report = ReportGenerator::generateReport(startDate, endDate);
            break;
        case 4: // Category Report
            report = ReportGenerator::generateCategoryReport(startDate, endDate, *category);
            break;
        default:
            throw std::runtime_error("Invalid report type selected.");
        }

        if (report.getExpenses().empty())
        {
            fl_message("No expenses found for the selected period.");
            return;
        }

        // Display the report in the reportDisplayArea
        reports_window->reportDisplayArea->clear();

        reports_window->reportDisplayArea->add(("\n\n\n\n\n\n" + report.generateReportDetails()).c_str());

        // Create a file if the checkbox is checked
        if (reports_window->createFileCheckButton->value() == 1)
        {
            report.generateFile();
            fl_message("Report file created successfully.");
        }
    }
    catch (const std::exception &e)
    {
        fl_alert(e.what());
    }
}

void UiReportsWindow::report_type_callback(Fl_Widget *widget, void *data)
{
    /**
     * @brief Handles the dynamic visibility of the UI elements based on the selected report type.
     *
     * This function checks the value of the selected report type and adjusts the visibility
     * of UI elements accordingly. It is called when the report type is changed.
     *
     * @param data A pointer to the UiReportsWindow object that contains the UI elements.
     */
    void UiReportsWindow::updateUIBasedOnReportType(void *data)
    {
        UiReportsWindow *reports_window = (UiReportsWindow *)data;
        int reportType = reports_window->reportTypeChoice->value();

        if (reportType == 3)
        { // Specific Report
            reports_window->endDayChoice->show();
            reports_window->endMonthChoice->show();
            reports_window->endYearChoice->show();
            reports_window->categoryChoice->hide();
        }
        else if (reportType == 4)
        { // Category Report
            reports_window->endDayChoice->show();
            reports_window->endMonthChoice->show();
            reports_window->endYearChoice->show();
            reports_window->categoryChoice->show();
        }
        else
        {
            reports_window->endDayChoice->hide();
            reports_window->endMonthChoice->hide();
            reports_window->endYearChoice->hide();
            reports_window->categoryChoice->hide();
        }
    }

    /**
     * @brief Destructor for UiReportsWindow.
     *
     * The destructor cleans up and releases resources allocated for the UI elements
     * within the UiReportsWindow object.
     */
    UiReportsWindow::~UiReportsWindow()
    {
        delete reportDisplayArea;
        delete reportTypeChoice;
        delete startDayChoice;
        delete startMonthChoice;
        delete startYearChoice;
        delete endDayChoice;
        delete endMonthChoice;
        delete endYearChoice;
        delete categoryChoice;
        delete generateButton;
        delete backButton;
        delete createFileCheckButton;
    }
