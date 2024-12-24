#Compiler
CXX = g++
CXXFLAGS = -std=c++11 -I C:\Users\HP\Documents\fltk-1.4.0-1-source\fltk-1.4.0-1 -I C:\fltk_build

# Linker Flags
LDFLAGS = -L C:\fltk_build\lib -lfltk -lcomctl32 -lole32 -luuid -lgdi32 -lws2_32 -lgdiplus -lwinspool -lcomdlg32

# Target
TARGET = main.exe

# Source Files
SRCS = AuthenticationManager.cpp Budget.cpp Category.cpp DateParser.cpp DateUtils.cpp Expense.cpp ExpenseManager.cpp FileManager.cpp MockClock.cpp NotificationManager.cpp RepeatedExpense.cpp Report.cpp ReportGenerator.cpp UiLoginWindow.cpp
User.cpp

# Build Rules
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	del $(TARGET)