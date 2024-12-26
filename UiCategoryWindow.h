#ifndef UI_CATEGORY_WINDOW_H
#define UI_CATEGORY_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Browser.H>
#include <FL/fl_ask.H>
#include <string>
#include "User.h"
#include "FileManager.h"
#include "UiMainWindow.h"

/**
 * @class UiCategoryWindow
 * @brief A window for managing categories within the application.
 * 
 * This class provides the user interface for adding new categories and viewing
 * the list of existing categories. It uses the FLTK library to create the
 * window and associated widgets for category management.
 */
class UiCategoryWindow : public Fl_Window {
private:
    Fl_Input* category_name_input; ///< Input widget for entering the category name.
    Fl_Button* add_button; ///< Button to add a new category.
    Fl_Button* cancel_button; ///< Button to cancel the category addition.
    Fl_Browser* category_list; ///< Browser widget to display the list of categories.

    /**
     * @brief Callback function for adding a new category.
     * 
     * This function is triggered when the "Add" button is clicked. It adds a
     * new category based on the user's input.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void add_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function for canceling the category addition.
     * 
     * This function is triggered when the "Cancel" button is clicked. It
     * closes the current window without making any changes.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void cancel_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Updates the list of categories displayed in the category list.
     * 
     * This function refreshes the category browser widget to show the most
     * up-to-date list of categories.
     */
    void updateCategoryList();

public:
    /**
     * @brief Constructs the window for managing categories.
     * 
     * Initializes the window with the appropriate size and sets up the
     * widgets for category input, adding, and canceling.
     * 
     * @param width The width of the window.
     * @param height The height of the window.
     */
    UiCategoryWindow(int width, int height);

    /**
     * @brief Destructor for cleaning up resources.
     */
    ~UiCategoryWindow();
};

#endif // UI_CATEGORY_WINDOW_H
