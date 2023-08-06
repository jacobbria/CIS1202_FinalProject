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
bool validate(const std::string& input);
void validate(int i);
std::vector<Bout> combineAllBouts(std::vector<Submission>& allSubmissions, std::vector<Knockout>& allKnockouts);
int mainMenu();
void enterBout(std::vector<Submission>& sub, std::vector<Knockout>& ko);
Submission createSubmission();
Knockout createKnockout();

// template to validate input within a specific range
template <typename T>
void validateInput(T& input, const T& minValue, const T& maxValue) {
	while (!(std::cin >> input) || input < minValue || input > maxValue) {
		std::cout << "Error! Please enter a valid number between " << minValue << " and " << maxValue << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

int main()
{
	std::vector<Bout> allBouts;	// vector to hold both submission and knockout finished bouts
	std::vector<Submission> allSubmissions; // vector to store all submission ended bouts
	std::vector<Knockout> allKnockouts; // vector to store all knockout ended bouts

	allBouts = combineAllBouts(allSubmissions, allKnockouts);	// combine submission and KO vectors into allBouts

	int menuChoice = 0;	// variable for user choice

	do {

		menuChoice = mainMenu();	// recieve choice from function call
		 
		switch (menuChoice) {	// switch to choose appropriate option
		case 1: 
			enterBout(allSubmissions, allKnockouts); // send vectors by reference to get updated with new bouts
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:
			break;
		}


	} while (menuChoice != 5);


	system("pause");
}

bool validate(const std::string& input) {	// validate string input
	return input.find('\n') == std::string::npos;
}
void validate(int i) {	// validate int input (overloaded)
	while (!cin) {
		std::cout << "Error! Please enter a valid number. " << endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
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
	cout << "Enter a selection: ";

	validateInput(userChoice, 1, 5);	// validate userChoice

	return userChoice;	// send the validated user input back to main
	
}
void enterBout(std::vector<Submission>& sub, std::vector<Knockout>& ko) {

	int finishChoice;	// variable to decide how fight was finished
	cout << "What method was this bout finished (0 for submission || 1 for knockout): ";
	
	validateInput(finishChoice, 0, 1); // validate the input

	cout << "Please enter the following information: " << endl;

	if (finishChoice == 0) {	// if a submission is selected

		Submission submission = createSubmission();	// create a new submission object

		sub.push_back(submission);	// fill allSubmissions vector with new submission objects
	}
	else {
		
		Knockout knockout = createKnockout();

		ko.push_back(knockout);

	}
	
}
Submission createSubmission() {	// creates a submission object to be sent back 
	Submission submission;	// submission object to send back

	std::string submissiontype;
	cout << "Submission type: ";
	getline(cin, submissiontype);
	submission.setSubmissionType(submissiontype);

	int position;
	cout << "Position submission was achieve from ( 0 = GUARD, 1 = MOUNT, 2 = BACK, 3 = TOP SIDE, 4 = BUTTOM SIDE, 5 = STANDING, 6 = OTHER): ";
	validateInput(position, 0, 6); // validate input
	submission.setPosition(position);
	
	std::string weightclass;
	cout << "Weight class: ";
	do {	// validate input
		getline(cin, weightclass);

		if (!validate(weightclass)) {
			std::cout << "Error: weightclass is incorrect length" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!validate(weightclass));
	submission.setWeightClass(weightclass);

	std::string winnerFirst;
	cout << "Winner's first name: ";
	do {	// validate input
		getline(cin, winnerFirst);

		if (!validate(winnerFirst)) {
			std::cout << "Error: name must be only one word" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!validate(winnerFirst));
	submission.setWinnerFirst(winnerFirst);

	std::string winnerLast;
	cout << "Winner's last name: ";
	do {	// validate input
		getline(cin, winnerLast);

		if (!validate(winnerLast)) {
			std::cout << "Error: name must be only one word" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!validate(winnerLast));
	submission.setWinnerLast(winnerLast);

	std::string loserFirst;
	cout << "Loser's first name: ";
	do {	// validate input
		getline(cin, loserFirst);

		if (!validate(loserFirst)) {
			std::cout << "Error: name must be only one word" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!validate(loserFirst));
	submission.setLoserFirst(loserFirst);

	std::string loserLast;
	cout << "Loser's last name: ";
	do {	// validate input
		getline(cin, loserLast);

		if (!validate(loserLast)) {
			std::cout << "Error: name must be only one word" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!validate(loserLast));
	submission.setLoserLast(loserLast);

	int minute;
	cout << "Minute stopped: ";
	do {
		cin >> minute;
		validate(minute); // validate input
	} while (!cin);
	submission.setMinute(minute);

	int seconds;
	cout << "seconds stopped: ";
	do {
		cin >> seconds;
		validate(seconds); // validate input
	} while (!cin);
	submission.setSeconds(seconds);

	int round;
	cout << "round stopped: ";
	do {
		cin >> round;
		validate(round); // validate input
	} while (!cin);
	submission.setRound(round);

	int year;
	cout << "Year bout occured: ";
	do {
		cin >> year;
		validate(year); // validate input
	} while (!cin);
	submission.setYear(year);



	return submission; // send created submission object back
}
Knockout createKnockout() {
	Knockout knockout;    // knockout object to send back

	std::string technique;
	cout << "Technique used for knockout: ";
	getline(cin, technique);
	knockout.setKnockoutTechnique(technique);

	std::string weightclass;
	cout << "Weight class: ";
	do {    // validate input
		getline(cin, weightclass);

		if (!validate(weightclass)) {
			std::cout << "Error: weightclass is incorrect length" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!validate(weightclass));
	knockout.setWeightClass(weightclass);

	std::string winnerFirst;
	cout << "Winner's first name: ";
	do {    // validate input
		getline(cin, winnerFirst);

		if (!validate(winnerFirst)) {
			std::cout << "Error: name must be only one word" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!validate(winnerFirst));
	knockout.setWinnerFirst(winnerFirst);

	std::string winnerLast;
	cout << "Winner's last name: ";
	do {    // validate input
		getline(cin, winnerLast);

		if (!validate(winnerLast)) {
			std::cout << "Error: name must be only one word" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!validate(winnerLast));
	knockout.setWinnerLast(winnerLast);

	std::string loserFirst;
	cout << "Loser's first name: ";
	do {    // validate input
		getline(cin, loserFirst);

		if (!validate(loserFirst)) {
			std::cout << "Error: name must be only one word" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!validate(loserFirst));
	knockout.setLoserFirst(loserFirst);

	std::string loserLast;
	cout << "Loser's last name: ";
	do {    // validate input
		getline(cin, loserLast);

		if (!validate(loserLast)) {
			std::cout << "Error: name must be only one word" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!validate(loserLast));
	knockout.setLoserLast(loserLast);

	int minute;
	cout << "Minute stopped: ";
	do {
		cin >> minute;
		validate(minute); // validate input
	} while (!cin);
	knockout.setMinute(minute);

	int seconds;
	cout << "seconds stopped: ";
	do {
		cin >> seconds;
		validate(seconds); // validate input
	} while (!cin);
	knockout.setSeconds(seconds);

	int round;
	cout << "round stopped: ";
	do {
		cin >> round;
		validate(round); // validate input
	} while (!cin);
	knockout.setRound(round);

	int year;
	cout << "Year bout occurred: ";
	do {
		cin >> year;
		validate(year); // validate input
	} while (!cin);
	knockout.setYear(year);

	return knockout; // send created knockout object back
}





