/*
 * Ethan Palombo
 * CS-210-H2919
 * November 2023
 * Project Two Airgead Banking
 */


#include <iostream>
#include <memory>
#include "Investment.h"

  // Constructors - see Investment.h for detailed discussion
  /*
   * The default constructor initializes the data members to logical default
   * values.
   */
Investment::Investment() {
	this->m_investmentAmount = 0;
	this->m_monthlyDeposit = 0;
	this->m_interestRate = 0;
	this->m_numberYears = 1;
}

/*
 * The parameterized constructor initializes the data members to the argument
 * values passed in by the class user in main().
 */
Investment::Investment(double t_investmentAmount, double t_interestRate, double t_numberYears, double t_monthlyDeposit /* default = 0 */) {
	this->m_investmentAmount = t_investmentAmount;
	this->m_monthlyDeposit = t_monthlyDeposit;
	this->m_interestRate = t_interestRate;
	this->m_numberYears = t_numberYears;
}

// Getters
double Investment::getInvestmentAmount() const {
	return this->m_investmentAmount;
}

double Investment::getMonthlyDeposit() const {
	return this->m_monthlyDeposit;
}

double Investment::getInterestRate() const {
	return this->m_interestRate;
}

double Investment::getNumberYears() const {
	return this->m_numberYears;
}

// Setters
void Investment::setInvestmentAmount(double t_investmentAmount) {
	this->m_investmentAmount = t_investmentAmount;
}

void Investment::setMonthlyDeposit(double t_monthlyDeposit) {
	this->m_monthlyDeposit = t_monthlyDeposit;
}

void Investment::setInterestRate(double t_interestRate) {
	this->m_interestRate = t_interestRate;
}

void Investment::setNumberYears(double t_numberYears) {
	this->m_numberYears = t_numberYears;
}