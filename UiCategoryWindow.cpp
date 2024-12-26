#include "UiCategoryWindow.h"
#include <iostream>

/**
 * @class UiCategoryWindow
 * @brief A window for adding and managing categories.
 * 
 * This class provides a UI for the user to add new categories and view a list of existing categories.
 */
UiCategoryWindow::UiCategoryWindow(int width, int height)
    : Fl_Window(width, height, "Add Category") {
    // Create input field for category name
    category_name_input = new Fl_Input(120, 20, 200, 30, "Category Name:");

    // Create buttons for adding and canceling the category
    add_button = new Fl_Button(120, 70, 90, 30, "Add");
    cancel_button = new Fl_Button(230, 70, 90, 30, "Cancel");

    // Create the browser to display the list of categories
    category_list = new Fl_Browser(120, 120, 200, 150, "Categories:");

    // Set callback functions for the buttons
    add_button->callback(add_callback, (void*)this);
    cancel_button->callback(cancel_callback, (void*)this);

    // Update the list of categories
    updateCategoryList();

    // Finalize the window setup
    end();
}

/**
 * @brief Destructor for UiCategoryWindow.
 * 
 * This destructor cleans up the allocated resources for the category window.
 */
UiCategoryWindow::~UiCategoryWindow() {
    delete category_name_input;
    delete add_button;
    delete cancel_button;
    delete category_list;
}

/**
 * @brief Callback function for adding a new category.
 * 
 * This function is triggered when the "Add" button is clicked. It adds the new category 
 * to the user's list of categories if the category name is provided.
 * 
 * @param widget The widget that triggered the callback.
 * @param data The window data.
 */
void UiCategoryWindow::add_callback(Fl_Widget* widget, void* data) {
    UiCategoryWindow* window = (UiCategoryWindow*)data;
    std::string category_name = window->category_name_input->value();

    // Check if the category name is empty
    if (category_name.empty()) {
        fl_alert("Category name must be filled out.");
        return;
    }

    // Add the new category to the user's categories
    User& user = FileManager::getMainUser();
    Category new_category(category_name);
    user.addCategory(new_category);

    // Save the updated data to the file
    FileManager::saveDataToFile(&user);

    // Print confirmation to the console
    std::cout << "Category added: " << category_name << std::endl;

    // Update the category list displayed in the window
    window->updateCategoryList();
}

/**
 * @brief Callback function for canceling the category creation process.
 * 
 * This function is triggered when the "Cancel" button is clicked, closing the current 
 * window and returning to the main window.
 * 
 * @param widget The widget that triggered the callback.
 * @param data The window data.
 */
void UiCategoryWindow::cancel_callback(Fl_Widget* widget, void* data) {
    UiCategoryWindow* window = (UiCategoryWindow*)data;
    window->hide();

    // Create and show the main window
    UiMainWindow* main_window = new UiMainWindow(window->w(), window->h());
    main_window->show();
}

/**
 * @brief Updates the list of categories displayed in the category browser.
 * 
 * This function retrieves the categories from the user and populates the category browser 
 * with the names of the categories.
 */
void UiCategoryWindow::updateCategoryList() {
    // Clear the current category list
    category_list->clear();

    // Retrieve the list of categories from the user
    User& user = FileManager::getMainUser();
    std::vector<Category> categories = user.getCategories();

    // Add each category to the list
    for (const auto& category : categories) {
        category_list->add(category.getCategoryName().c_str());
    }
}
