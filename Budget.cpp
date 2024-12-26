#include "Budget.h"

/**
 * @brief Constructs a Budget object with the specified parameters.
 * 
 * @param id Unique identifier for the budget.
 * @param name Name of the budget.
 * @param amount Total allocated amount for the budget.
 * @param spentAmount Amount already spent from the budget.
 * @param date Start date of the budget.
 * @param endDate End date of the budget.
 * @param source Source of the budget, such as income type or funding origin.
 */
Budget::Budget(int id, string name, double amount, double spentAmount, std::chrono::system_clock::time_point date, std::chrono::system_clock::time_point endDate, string source){
	this->id = id;
	this->name = name;
	this->amount = amount;
	this->spentAmount = spentAmount;
	this->date = date;
	this->endDate = endDate;
	this->source = source;
}

/**
 * @brief Gets the name of the budget.
 * 
 * @return The name of the budget as a string.
 */
string Budget::getName() const
{
	return name;
}

/**
 * @brief Gets the unique identifier of the budget.
 * 
 * @return The unique identifier as an integer.
 */
int Budget::getID() const
{
	return id;
}

/**
 * @brief Gets the time interval of the budget in string format.
 * 
 * Combines the start and end dates into a single string.
 * 
 * @return The time interval in the format "startDate-endDate".
 */
string Budget::getTimeInterval() const
{
	return DateUtils::timePointToString(this->date) + "-" + DateUtils::timePointToString(this->endDate);
}

/**
 * @brief Updates the spent amount of the budget.
 * 
 * Adds the specified value to the total spent amount.
 * 
 * @param newSpentAmount The amount to add to the total spent amount.
 */
void Budget::setSpentAmount(double newSpentAmount)
{
	spentAmount += newSpentAmount;
}

/**
 * @brief Gets the total amount spent from the budget.
 * 
 * @return The total spent amount as a double.
 */
double Budget::getSpentAmount() const
{
	return spentAmount;
}

/**
 * @brief Sets the source details of the budget.
 * 
 * Updates the source information, such as where the budget originates from.
 * 
 * @param newSource The new source details as a string.
 */
void Budget::setSourceDetails(string newSource)
{
	source = newSource;
}

/**
 * @brief Gets the source details of the budget.
 * 
 * @return The source details as a string.
 */
string Budget::getSourceDetails() const
{
	return source;
}

/**
 * @brief Updates the allocated amount for the budget.
 * 
 * Sets a new total budget amount.
 * 
 * @param newAmount The new budget amount.
 */
void Budget::setBudgetAmount(double newAmount)
{
	amount = newAmount;
}

/**
 * @brief Gets the allocated amount for the budget.
 * 
 * @return The allocated amount as a double.
 */
double Budget::getBudgetAmount() const
{
	return amount;
}

/**
 * @brief Gets the start date of the budget.
 * 
 * @return The start date as a std::chrono::system_clock::time_point.
 */
std::chrono::system_clock::time_point Budget::getStartDate() const
{
	return date;
}

/**
 * @brief Gets the end date of the budget.
 * 
 * @return The end date as a std::chrono::system_clock::time_point.
 */
std::chrono::system_clock::time_point Budget::getEndDate() const
{
	return endDate;
}
