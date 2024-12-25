#ifndef BUDGET_H
#define BUDGET_H

#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Budget
{
private:
	string name;
	int id;
	double amount;
	double spentAmount;
	string date;
	string endDate;
	string source;

public:
	Budget(string name, double amount, string date, string endDate, string source);
	string getName() const;
	int getID() const;
	string getTimeInterval() const;
	void setSpentAmount(double newSpentAmount);
	double getSpentAmount() const;
	void setSourceDetails(string newSource);
	string getSourcetDetails() const;
	void setBudgetAmount(double newAmount);
	double getBudgetAmount() const;

	bool operator==(const Budget& other) const {
        return id == other.id;
    }
};

#endif // !BUDGET_H
