#include "Budget.h"

#include <stdlib.h>
#include <time.h>

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

string Budget::getName()
{
	return this->name;
}

int Budget::getID()
{
	return this->id;
}

string Budget::getTimeInterval()
{
	return this->date + "-" + this->endDate;
}

void Budget::setSpentAmount(double newSpentAmount)
{
	// Updating total spent amount from budget
	this->spentAmount += newSpentAmount;
}

double Budget::getSpentAmount()
{
	// Accesing total spent amount
	return this->spentAmount;
}

void Budget::setSourceDetails(string newSource)
{
	// Changing source of the budget
	this->source = newSource;
}

string Budget::getSourcetDetails()
{
	// Accesing source of the budget
	return this->source;
}

void Budget::setBudgetAmount(double newAmount)
{
	// Updating the amount
	this->amount = newAmount;
}

double Budget::getBudgetAmount()
{
	// Accessing budget amount
	return this->amount;
}