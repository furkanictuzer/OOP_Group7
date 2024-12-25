#ifndef BUDGET_H
#define BUDGET_H

#include <string>
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
	string getName();
	int getID();
	string getTimeInterval();
	void setSpentAmount(double newSpentAmount);
	double getSpentAmount();
	void setSourceDetails(string newSource);
	string getSourcetDetails();
	void setBudgetAmount(double newAmount);
	double getBudgetAmount();
};

#endif // !BUDGET_H
