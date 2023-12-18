/*
 * Ethan Palombo
 * CS-210-H2919
 * November 2023
 * Project Two Airgead Banking
 */

#include <iostream>
#include <memory>	// Library needed for smart pointers


#include "Investment.h"
#include "bankFunctions.h"

using namespace std;

int main() {

	/*
	 *  Capture the investment amount, interest rate, number of years, and optional
	 *  monthly deposit amount and create an investment object from the input provided.
	 *  The variables are pointer types.  Using pointers promotes memory preservation
	 *  and program efficiency, operating on a single heap value pointed to by the variable
	 *  in lieu of a separate stack copy that occupies additional memory.
	 *  Smart pointers are used in lieu of standard pointers to promote safety and prevention
	 *  of memory leaks.  Smart pointers ensure an object is deleted if it
	 *  is no longer used.  Smart pointers are wrappers that eliminate the need for
	 *  explicitly using the 'new' and 'delete' keywords, which are handled automatically.
	 *  While unique pointers are the preferred type of smart pointer for most cases, shared pointers
	 *  are used here as multiple references are created- (1) initially during variable declaration
	 *  and (2) at function call (i.e. the local argument references the same value in memory).
	 *  Once the pointer is out of scope it is automatically deleted.
	 *  For shared pointers, scope dies when the reference count equals 0.
	 *  Here, reference count will hit 1 during initial variable creation and spike to 2 during
	 *  the call to investmentSimulation(), drop back to 1 when investmentSimulation()
	 *  returns, and then finally drop to 0 when main() returns.
	 */

	 // Open the program with an empty snapshot
	printInvestmentSnapshot();
	// Capture user input for initial amounts and instantiate object
	shared_ptr<double> investmentAmount(new double(inputInvestment("Enter initial investment amount: ")));
	shared_ptr<double> interestRate(new double(inputInterestRate("Enter rate of interest: ")));
	shared_ptr<double> numberYears(new double(inputNumberYears("Enter investment duration (in years): ")));
	shared_ptr<double> depositAmount(new double(grabDepositAmout()));
	Investment myInvestment(*investmentAmount, *interestRate, *numberYears, *depositAmount);
	// Display the snapshot with updated investment information
	printInvestmentSnapshot(myInvestment);
	// Print initial investment growth charts with and without monthly deposits
	printGrowth(myInvestment, false);
	cout << endl;
	printGrowth(myInvestment, true);
	cout << endl << endl << endl;
	// Display an options menu, loop through user actions until the user opts to quit
	investmentSimulation(myInvestment, investmentAmount, interestRate, numberYears, depositAmount);
	cout << endl << "Goodbye.";
	return 0;
}