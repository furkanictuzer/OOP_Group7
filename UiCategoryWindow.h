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

class UiCategoryWindow : public Fl_Window {
private:
    Fl_Input* category_name_input;
    Fl_Button* add_button;
    Fl_Button* cancel_button;
    Fl_Browser* category_list;

    static void add_callback(Fl_Widget* widget, void* data);
    static void cancel_callback(Fl_Widget* widget, void* data);

    void updateCategoryList();

public:
    UiCategoryWindow(int width, int height);
    ~UiCategoryWindow();
};

#endif // UI_CATEGORY_WINDOW_H