/*
 * Ethan Palombo
 * CS-210-H2919
 * November 2023
 * Project Two Airgead Banking
 */

#include <iostream>             // Library needed for cin and cout objects
#include <stdexcept>            // Library needed for the runtime_error object to be
 // thrown/caught in exception handling cases
#include <string>				// C++ string class library
#include <stdlib.h>
#include <iomanip>				// set precision for numerical calculation output
#include <memory>
#include "Investment.h"

using namespace std;

/*
 * Function to prompt a user for numerical input and return the input
 * for storing in a variable to be passed into an investment object (e.g.
 * investment amount, monthly deposit, etc.)
 */
double getDouble(string t_prompt) {
	bool validEntry;			// flag to drive exception handling
	string userEntryAsString;	// store user input to convert to double
	double userEntry;			// store user input as double to return

	/*
	 * Exception handling to validate user entry.
	 * A do-while loop is used because the prompt
	 * should be displayed at least once and assume the user
	 * enters valid input. Don't initiate a loop until an exception is thrown.
	 */
	do {
		validEntry = true;		// assume initially the entry will be valid
		try {
			cout << t_prompt << endl;
			cin >> userEntryAsString;
			/*
			 * The stod method of the string class parses the string argument,
			 * interprets its content as a floating-point number, and returns the
			 * result of type double.
			 */
			userEntry = stod(userEntryAsString);
		}
		// Catch an invalid argument (e.g. user enters a string in lieu of double)
		catch (invalid_argument& excpt) {
			cout << "Invalid entry type, please enter a number." << endl << endl;
			validEntry = false;
		}
	} while (!validEntry);
	return userEntry;
}

/*
 * Function to prompt a user for investment amount and return it
 * for storing in a variable to be passed into an investment object.
 * Uses exception handling to ensure the investment amount is greater than zero.
 */
double inputInvestment(string t_prompt) {
	bool validEntry;			// flag to drive exception handling
	double investmentAmount;	// store and return the investment amount

	/*
	 * Standard exception handling do-while loop.  See getDouble()
	 * for additional details.
	 */
	do {
		validEntry = true;		// assume initially the entry will be valid
		try {
			investmentAmount = getDouble(t_prompt);
			if (investmentAmount <= 0) {
				throw runtime_error("Invalid entry. Please enter an amount greater than $0.");
			}
		}
		// Catch an investment amount 0 or less
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while (!validEntry);

	return investmentAmount;
}

/*
 * Function to prompt a user for deposit amount and return it
 * for storing in a variable to be passed into an investment object.
 * Uses exception handling to ensure the deposit is greater than zero.
 */
double inputDeposit(string t_prompt) {
	bool validEntry;			// flag to drive exception handling
	double depositAmount;		// store and return the deposit amount

	/*
	 * Standard exception handling do-while loop.  See getDouble()
	 * for additional details.
	 */
	do {
		validEntry = true;		// assume initially the entry will be valid
		try {
			depositAmount = getDouble(t_prompt);
			if (depositAmount <= 0) {
				throw runtime_error("Invalid entry. Please enter an amount greater than $0.");
			}
		}
		// Catch a deposit amount 0 or less
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while (!validEntry);

	return depositAmount;
}

/*
 * Function to prompt a user for an interest rate and return it
 * for storing in a variable to be passed into an investment object.
 * Uses exception handling to ensure the interest rate is not negative.
 */
double inputInterestRate(string t_prompt) {
	bool validEntry;			// flag to drive exception handling
	double interestRate;		// store and return the interest rate

	/*
	 * Standard exception handling do-while loop.  See getDouble()
	 * for additional details.
	 */
	do {
		validEntry = true;		// assume initially the entry will be valid
		try {
			interestRate = getDouble(t_prompt);
			if (interestRate < 0) {
				throw runtime_error("Invalid entry. Please enter a non-negative interest rate.");
			}
		}
		// Catch an interest rate less than 0
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while (!validEntry);

	return interestRate;
}

/*
 * Function to prompt a user for number of years and return it
 * for storing in a variable to be passed into an investment object.
 * Uses exception handling to ensure the number of years are 1 or more.
 */
double inputNumberYears(string t_prompt) {
	bool validEntry;			// flag to drive exception handling
	double numberYears;			// store and return the number of years

	/*
	 * Standard exception handling do-while loop.  See getDouble()
	 * for additional details.
	 */
	do {
		validEntry = true;		// assume initially the entry will be valid
		try {
			numberYears = getDouble(t_prompt);
			if (numberYears < 1) {
				throw runtime_error("Invalid entry. Please enter 1 year or more.");
			}
		}
		// Catch years less than 1
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while (!validEntry);

	return numberYears;
}

/*
 * Prompt the user to enter a deposit amount if desired
 */
double grabDepositAmout() {
	bool validEntry;				// flag to drive exception handling
	double depositAmount;			// store and return the number of years
	char userEntry;

	/*
	 * Standard exception handling do-while loop.  See getDouble()
	 * for additional details.
	 */
	do {
		validEntry = true;		// assume initially the entry will be valid
		try {
			cout << "Would you like to add a monthly deposit (Y/N)? ";
			cin >> userEntry;
			if ((userEntry != 'N') && (userEntry != 'n') && (userEntry != 'Y') && (userEntry != 'y')) {
				throw runtime_error("Invalid entry. Please enter Y or N.");
			}
		}
		// Catch invalid input
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while (!validEntry);

	if ((userEntry == 'Y') || (userEntry == 'y')) {
		depositAmount = inputDeposit("Please enter your deposit amount.");
	}
	else {
		depositAmount = 0;
	}
	return depositAmount;
}

/*
 * Function to print horizontal borders.  Loop through the length
 * given and print the character given for that many horizontal columns.
 */
void printHorizontalBorder(int t_length, char t_printChar) {
	for (int i = 0; i < t_length; ++i) {
		cout << t_printChar;
	}
	return;
}

/*
 * Function to display the investment attributes (e.g. amount, years interest).
 * Function uses overloading to determine output based on arguments provided
 * in the function call.  The version without parameters is intended for the
 * initial part of the program before any investment object is instantiated.
 * The Investment object in the overloaded function
 * is passed in by reference to avoid an additional copy for performance savings
 * and per the standards.  No object data members are manipulated or returned
 * from this function.
 */
void printInvestmentSnapshot() {
	const int MENU_WIDTH = 35;			// Column width of the menu
	string menuTitle = "Data Input";	// menu title
	char menuChar = '*';
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2) - 1), menuChar);
	cout << " " << menuTitle << " ";
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2)), menuChar);
	cout << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of Years: " << endl;
	system("pause");		// wait for user input to continue
							// added bonus of displaying 'Press any key to continue...'
	return;
}

void printInvestmentSnapshot(Investment& t_investment) {
	const int MENU_WIDTH = 35;			// Column width of the menu
	string menuTitle = "Data Input";	// menu title
	char menuChar = '*';
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2) - 1), menuChar);
	cout << " " << menuTitle << " ";
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2)), menuChar);
	cout << endl;
	cout << "Initial Investment Amount: $" << t_investment.getInvestmentAmount() << endl;
	cout << "Monthly Deposit: $" << t_investment.getMonthlyDeposit() << endl;
	cout << "Annual Interest: " << t_investment.getInterestRate() << "%" << endl;
	cout << "Number of Years: " << t_investment.getNumberYears() << endl;
	system("pause");
	return;
}

/*
 * Function to display growth output, both with and without a monthly deposit
 * amount accounted for.  The Investment object is passed in
 * by reference to avoid an additional copy for performance savings and per the standards.
 * No object data members are manipulated or returned from this function.
 * NOTE: The alignment on this output is not perfect once years and/or amounts start to get large,
 * I tried several approaches of varying complexity and ultimately reduced it to cout << "\t\t"
 * which is still imperfect.  As such, alignment of the column output for year, earned interest,
 * and end balance may be off target for certain test cases.  This is a known bug.
 */

void printGrowth(Investment& t_investment, bool t_withMonthly/* default is false */) {
	const int MENU_WIDTH = 75;
	const double MONTHS_IN_YEAR = 12.00;
	string menuTitleNoDeposit = "Balance and Interest - No Additional Deposits";
	string menuTitleWithDeposits = "Balance and Interest - With Monthly Deposits";
	string menuTitle;
	if (t_withMonthly) {
		menuTitle = menuTitleWithDeposits;
	}
	else {
		menuTitle = menuTitleNoDeposit;
	}
	int menuTitleWhiteSpace = MENU_WIDTH - menuTitle.length();	// Title marquee whitespace
	string headerOne = "Year";
	string headerTwo = "Interest Earned";
	string headerThree = "Year End Balance";
	char menuChar = '=';
	char outputChar = ' ';
	// Print title top border
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	// Print title leading whitespace
	printHorizontalBorder((menuTitleWhiteSpace / 2), outputChar);
	// Print menu title
	cout << menuTitle;
	// Print title trailing whitespace
	printHorizontalBorder((menuTitleWhiteSpace / 2), outputChar);
	cout << endl;
	// Print title bottom border
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	// Print column one header
	cout << "\t" << headerOne;
	// Print column two header
	cout << "\t\t" << headerTwo;
	// Print column three header
	cout << "\t\t" << headerThree;
	cout << endl;
	// Prior to calculating and outputting growth, level set investment amount
	// to use as the beginning balance for the investment growth output.
	double begBalance = t_investment.getInvestmentAmount();
	// Loop through the number of years for the investment.
	// For each year, calculate the interest earned, ending balance, and output results.
	// Logic drives whether to include monthly deposits based on the flag
	// passed during the function call.
	for (int i = 0; i < t_investment.getNumberYears(); ++i) {
		int year = (i + 1);		// Add 1 to i for the appropriate year output display
		double interestRate = t_investment.getInterestRate() / 100.00;
		double interestEarned;
		double totalInterest;
		double endBalance;
		double monthEndBalance;
		if (t_withMonthly) {		// Include monthly deposits in growth output
			interestEarned = 0;
			totalInterest = 0;
			interestRate = interestRate / MONTHS_IN_YEAR;
			for (int i = 0; i < MONTHS_IN_YEAR; ++i) {
				// Assumes deposit is made at the beginning of the month per spec given
				begBalance += t_investment.getMonthlyDeposit();
				interestEarned = (begBalance * (1 + interestRate)) - begBalance;
				monthEndBalance = begBalance + interestEarned;
				begBalance = monthEndBalance;
				totalInterest += interestEarned;
			}
		}
		else {					// Do not include monthly deposits
			totalInterest = (begBalance * (1 + interestRate)) - begBalance;
		}
		if (t_withMonthly) {
			// The above loop sets the beginning balance to the end of period
			// balance to start the next iteration.  This will set begBalance to
			// the true end of year balance at loop exit.
			endBalance = begBalance;
		}
		else {
			endBalance = begBalance + totalInterest;
			begBalance = endBalance;	// set beginning balance equal to ending balance for next iteration
		}
		// Print column one output
		cout << "\t" << year;
		// Print column two output, fixed to 2 decimal places
		cout << "\t\t" << "$" << setprecision(2) << fixed << totalInterest;
		// Print column three output, fixed to 2 decimal places
		cout << "\t\t\t" << "$" << setprecision(2) << fixed << endBalance;
		cout << endl;
	}
	return;			// clear the stack even though return type is void
}

/*
 * Function to display options menu, called by investmentSimulation.
 */
void printOptions() {
	string optionsMenu = "What would you like to do?\n"
		"1 - Change Initial Investment Amount\n"
		"2 - Change Monthly Deposit Amount\n"
		"3 - Change Interest Rate\n"
		"4 - Change Investment Duration (years)\n"
		"5 - Print Investment Growth - No Deposit\n"
		"6 - Print Investment Growth - With Deposits\n"
		"7 - Quit.";
	const int MENU_WIDTH = 50;
	const char MENU_CHAR = '*';
	printHorizontalBorder(MENU_WIDTH, MENU_CHAR);
	cout << endl;
	cout << optionsMenu;
	cout << endl;
	printHorizontalBorder(MENU_WIDTH, MENU_CHAR);
	cout << endl;
	return;
}

/*
 * Function to loop through menu functions to allow user to take additional action.
 * Per the spec, the user The user should be able to test different monthly deposit
 * amounts, interest rates, and lengths of time to see how increases and decreases
 * impact their investment growth.
 */
void investmentSimulation(Investment& t_investment, std::shared_ptr<double> t_investmentAmount,
	std::shared_ptr<double> t_interestRate, std::shared_ptr<double> t_numberYears,
	std::shared_ptr<double> t_depositAmount) {

	bool validEntry;			// flag to drive exception handling
	string userEntryAsString;	// store user input to convert to double
	int userEntry = 0;			// store user input as int to drive case statement
								// initialize to zero to drive initial loop
	/*
	 * Loop until user opts to quit (e.g. userEntry == 7).  A while loop is
	 * used because the number of loop iterations is unknown and is driven by user input.
	 */
	while (userEntry != 7) {
		/*
		 * Exception handling to validate user entry.
		 * A do-while loop is used because the prompt
		 * should be displayed at least once and assume the user
		 * makes a valid selection. Don't initiate a loop until an exception is thrown.
		 */
		do {
			validEntry = true;		// assume initially the entry will be valid
			try {
				printOptions();
				cin >> userEntryAsString;
				userEntry = stoi(userEntryAsString);	// stoi is a quick way to convert a string to an int
				if ((userEntry < 1) || (userEntry > 7)) {
					throw runtime_error("Invalid entry. Please enter a number between 1 and 7");
				}
			}
			// Catch an invalid argument (e.g. user enters a string in lieu of int)
			catch (invalid_argument& excpt) {
				cout << "Invalid entry type, please enter a number." << endl << endl;
				validEntry = false;
			}
			catch (runtime_error& excpt) {
				cout << excpt.what() << endl << endl;
				validEntry = false;
			}
		} while (!validEntry);
		cout << endl;
		/*
		 * The user option chosen dictates the path taken.  Loop until user quits.
		 * A while loop is used because the number of iterations is unknown at loop entry.
		 * A switch statement is used in lieu of if-else because there is a larger set of options.
		 * The switch statement keeps the code a bit cleaner here.
		 */
		switch (userEntry) {
		case 1:	// Change the investment amount
			// Print the current Snapshot
			printInvestmentSnapshot(t_investment);
			*t_investmentAmount = inputInvestment("Enter new investment amount: ");
			t_investment.setInvestmentAmount(*t_investmentAmount);
			// Print the new snapshot
			printInvestmentSnapshot(t_investment);
			break;		// if a case is executed, break out of the switch statement so other cases aren't executed
		case 2:	// Change the deposit amount
			// Print the current Snapshot
			printInvestmentSnapshot(t_investment);
			*t_depositAmount = inputDeposit("Enter new deposit amount: ");
			t_investment.setMonthlyDeposit(*t_depositAmount);
			// Print the new snapshot
			printInvestmentSnapshot(t_investment);
			break;
		case 3:	// Change the interest rate
			// Print the current Snapshot
			printInvestmentSnapshot(t_investment);
			*t_interestRate = inputInterestRate("Enter new interest rate: ");
			t_investment.setInterestRate(*t_interestRate);
			// Print the new snapshot
			printInvestmentSnapshot(t_investment);
			break;
		case 4:	// Change the investment duration
			// Print the current Snapshot
			printInvestmentSnapshot(t_investment);
			*t_numberYears = inputNumberYears("Enter new duration: ");
			t_investment.setNumberYears(*t_numberYears);
			// Print the new snapshot
			printInvestmentSnapshot(t_investment);
			break;
		case 5:
			printGrowth(t_investment, false);
			cout << endl << endl;
			break;
		case 6:
			printGrowth(t_investment, true);
			cout << endl << endl;
			break;
		default:		// path taken if no other cases are executed, this will capture choice to quit program
			break;
		}
	}
	return;
}