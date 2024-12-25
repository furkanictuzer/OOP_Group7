#include "UiCategoryWindow.h"
#include <iostream>
UiCategoryWindow::UiCategoryWindow(int width, int height)
    : Fl_Window(width, height, "Add Category") {
    category_name_input = new Fl_Input(120, 20, 200, 30, "Category Name:");

    add_button = new Fl_Button(120, 70, 90, 30, "Add");
    cancel_button = new Fl_Button(230, 70, 90, 30, "Cancel");

    category_list = new Fl_Browser(120, 120, 200, 150, "Categories:");

    add_button->callback(add_callback, (void*)this);
    cancel_button->callback(cancel_callback, (void*)this);

    updateCategoryList();

    end();
}

UiCategoryWindow::~UiCategoryWindow() {
    delete category_name_input;
    delete add_button;
    delete cancel_button;
    delete category_list;
}

void UiCategoryWindow::add_callback(Fl_Widget* widget, void* data) {
    UiCategoryWindow* window = (UiCategoryWindow*)data;
    std::string category_name = window->category_name_input->value();

    if (category_name.empty()) {
        fl_alert("Category name must be filled out.");
        return;
    }

    User& user = FileManager::getMainUser();
    Category new_category(category_name);
    user.addCategory(new_category);

    FileManager::saveDataToFile(&user);

    std::cout << "Category added: " << category_name << std::endl;

    window->updateCategoryList();
}

void UiCategoryWindow::cancel_callback(Fl_Widget* widget, void* data) {
    UiCategoryWindow* window = (UiCategoryWindow*)data;
    window->hide();

    UiMainWindow* main_window = new UiMainWindow(window->w(), window->h());
    main_window->show();
}

void UiCategoryWindow::updateCategoryList() {
    category_list->clear();
    User& user = FileManager::getMainUser();
    std::vector<Category> categories = user.getCategories();

    for (const auto& category : categories) {
        category_list->add(category.getCategoryName().c_str());
    }
}