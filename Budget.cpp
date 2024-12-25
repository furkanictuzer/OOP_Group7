#include "Budget.h"

Budget::Budget(string name, double amount, string date, string endDate, string source)
{
	// Initializing attirbutes
	this->name = name;
	srand(time(0));
	this->id = rand() % 10000; // Budget id is determined randomly
	this->amount = amount;
	this->date = date;
	this->endDate = endDate;
	this->source = source;
	this->spentAmount = 0;
}

string Budget::getName() const
{
	return name;
}

int Budget::getID() const
{
	return id;
}

string Budget::getTimeInterval() const
{
	return date + "-" + this->endDate;
}

void Budget::setSpentAmount(double newSpentAmount)
{
	// Updating total spent amount from budget
	spentAmount += newSpentAmount;
}

double Budget::getSpentAmount() const
{
	// Accesing total spent amount
	return spentAmount;
}

void Budget::setSourceDetails(string newSource)
{
	// Changing source of the budget
	source = newSource;
}

string Budget::getSourcetDetails() const
{
	// Accesing source of the budget
	return source;
}

void Budget::setBudgetAmount(double newAmount)
{
	// Updating the amount
	amount = newAmount;
}

double Budget::getBudgetAmount() const
{
	// Accessing budget amount
	return amount;
}