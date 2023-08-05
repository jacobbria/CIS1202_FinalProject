// Jacob Bria
// CIS 1202(final)
// 08/04/2023
// MMA bout finish program
// Enter in a MMA bout that ended with a finish and get resultant statistics

#include <iostream>
#include "Bout.h"	// parent class
#include "Submission.h"	// child class for a bout ended in a submission
#include "Knockout.h"
#include <vector>
using std::cout; // save time with cout lines
using std::endl;
using std::cin;

// prototypes
std::vector<Bout> combineAllBouts(std::vector<Submission>& allSubmissions, std::vector<Knockout>& allKnockouts);
int mainMenu();

int main()
{
	std::vector<Bout> allBouts;	// vector to hold both submission and knockout finished bouts
	std::vector<Submission> allSubmissions; // vector to store all submission ended bouts
	std::vector<Knockout> allKnockouts; // vector to store all knockout ended bouts

	allBouts = combineAllBouts(allSubmissions, allKnockouts);	// combine submission and KO vectors into allBouts

	int menuChoice = 0;	// variable for user choice

	do {

		menuChoice = mainMenu();

	} while (menuChoice != 5);



	system("pause");
}

std::vector<Bout> combineAllBouts(std::vector<Submission>& allSubmissions, std::vector<Knockout>& allKnockouts) {

	std::vector<Bout> combinedBouts;

	// Insert all submissions
	for (size_t i = 0; i < allSubmissions.size(); ++i) {
		combinedBouts.push_back(allSubmissions[i]);
	}

	// Insert all knockouts
	for (size_t i = 0; i < allKnockouts.size(); ++i) {
		combinedBouts.push_back(allKnockouts[i]);
	}


	return combinedBouts;
}
int mainMenu() {

	int userChoice = -1;	// variable to hold a users choice for the menu

	cout << "1. Enter Bout" << endl;
	cout << "2. List All Bouts" << endl;
	cout << "3. Leaderboards" << endl;
	cout << "4. Random Fact Generator" << endl;
	cout << "5. Exit" << endl;
	cout << endl;

	while (!cin || userChoice < 1 || userChoice > 5) {	// code block to validate user input
		cout << "Enter a selection: ";
		cin >> userChoice;	// get user input

		if (!cin || userChoice < 1 || userChoice > 5) {	// error in input
			cout << "Error! Please enter a valid number 1-5" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
		return userChoice;	// send the validated user input back to main
	
}


