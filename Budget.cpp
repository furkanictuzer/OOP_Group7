#include "Budget.h"

Budget::Budget(int id, string name, double amount, double spentAmount, std::chrono::system_clock::time_point date, std::chrono::system_clock::time_point endDate, string source){
	this->id = id;
	this->name = name;
	this->amount = amount;
	this->spentAmount = spentAmount;
	this->date = date;
	this->endDate = endDate;
	this->source = source;
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
	return DateUtils::timePointToString(this->date) + "-" + DateUtils::timePointToString(this->endDate);
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

string Budget::getSourceDetails() const
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

std::chrono::system_clock::time_point Budget::getStartDate() const
{
	// Accessing start date
	return date;
}

std::chrono::system_clock::time_point Budget::getEndDate() const
{
	// Accessing end date
	return endDate;
}