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
#include <cstdlib>
#include <ctime> 
using std::cout; // save time with cout lines
using std::endl;
using std::cin;

struct quickestFactStruct {	// struct for use in random fact generator

	std::string quickestFirst;
	std::string quickestLast;
	int quickestYear;
	int quickestMin;
	int quickestSec;
};

// prototypes
bool validate(const std::string& input);	// validate strings for one-word
void validate(int i); // validate ints

std::vector<Bout> combineAllBouts(std::vector<Submission>& allSubmissions, std::vector<Knockout>& allKnockouts);	// adds two finish type vectors to one vector

int mainMenu(); // creates a user driven menu

void enterBout(std::vector<Submission>& sub, std::vector<Knockout>& ko); // user enters a Bout
Submission createSubmission(); // creates submission object for use in vector
Knockout createKnockout();	// creates a knockout object for use in vector

void listBouts(std::vector<Bout>& allBouts, std::vector<Submission>& allSub, std::vector<Knockout>& allKO);	// prints out desired bouts

void displayFacts(std::vector<Submission>&, std::vector<Knockout>&); // will display random facts based on entered input
void generateRandomFact(std::vector<std::string>& facts, std::vector<Submission>& allSub, std::vector<Knockout>& allKo); // generates random facts
int randomNumberGenerator(std::vector<std::string>);	// will generate a random number
std::vector<quickestFactStruct> findQuickestSubmissions(const std::vector<Submission>& allSub); // find the quickest submission
std::vector<quickestFactStruct> findQuickestKnockouts(const std::vector<Knockout>&);	// find quickest KO


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
			listBouts(allBouts, allSubmissions, allKnockouts);	// send the vectors to loop and print all fights
			break;
		case 3:

			break;
		case 4:
			displayFacts(allSubmissions, allKnockouts);
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
	cout << "2. List Bouts" << endl;
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

	cin.ignore();

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
	cin.ignore(); // absord the newline
	
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
	cin.ignore();
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
void listBouts(std::vector<Bout>& allBouts,std::vector<Submission>& allSub,std::vector<Knockout>& allKO) {
	int selection;
	do {
		cout << "Select one to list (0 = submissions || 1 = knockouts || 2 = both || 3 = exit): ";
		cin >> selection;
		validateInput(selection, 0, 3); // validate input

		if (selection == 0) {	// submission bouts
			cout << "All Fights Ending In Submission:" << endl;
			for (int i = 0; i < allSub.size(); i++) {
				cout << allSub[i].getBoutTitle() << " (" << allSub[i].getYear() << ")" << endl;
				cout << "------------------------" << endl;
				cout << "Winner: " << allSub[i].getWinnerLast() << ", " << allSub[i].getWinnerFirst() << endl;
				cout << "By " << allSub[i].getSubmissionType() << " from " << allSub[i].getpositionToString() << " in round " << allSub[i].getRound()
					<< " at " << allSub[i].getMinute() << ":" << allSub[i].getSeconds() << endl;
			}
		}
		else if (selection == 1) {	// knockout bouts
			cout << "All Fights Ending In Knockout:" << endl;
			for (int i = 0; i < allKO.size(); i++) {
				cout << allKO[i].getBoutTitle() << " (" << allKO[i].getYear() << ")" << endl;
				cout << "------------------------" << endl;
				cout << "Winner: " << allKO[i].getWinnerLast() << ", " << allKO[i].getWinnerFirst() << endl;
				cout << "By " << allKO[i].getKnockoutTechnique() << " in round " << allKO[i].getRound()
					<< " at " << allKO[i].getMinute() << ":" << allKO[i].getSeconds() << endl;
			}
		}
		else if (selection == 2) {	// all bouts
			cout << "All Bouts:" << endl;
			for (int i = 0; i < allBouts.size(); i++) {
				cout << allBouts[i].getBoutTitle() << " (" << allBouts[i].getYear() << ")" << endl;
				cout << "------------------------" << endl;
				
			}

		}
		
	} while (selection != 3);
}
void displayFacts(std::vector<Submission>& allSubs, std::vector<Knockout>& allKo) {
	std::vector<std::string> facts(2);	// vector to hold facts

	int selection = 0; // flag for user to generate or exit 
	do {
		cout << "(0 for a new fact || 1 to exit) " << endl;
		cin >> selection;
		validateInput(selection, 0, 1); // validate input

		generateRandomFact(facts, allSubs, allKo); // call random fact generator to fill vector will facts
		int randomNum = randomNumberGenerator(facts);	// get random number based on size of vector

		cout << facts[randomNum] << endl;	// generate a fact
		
	} while (selection != 1);
}
int randomNumberGenerator(std::vector<std::string> facts) {
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // seed random number generator
	int randomIndex = std::rand() % facts.size(); // generate random number based on vector size

	return randomIndex;
}
void generateRandomFact(std::vector<std::string>& facts, std::vector<Submission>& allSub, std::vector<Knockout>& allKo) {
    std::vector<quickestFactStruct> quickestSubmissions = findQuickestSubmissions(allSub);

    std::string factOne = "The quickest submission was ";
    for (const auto& sub : quickestSubmissions) {
        factOne += sub.quickestFirst + " " + sub.quickestLast + " at " + std::to_string(sub.quickestMin) + ":" +
         std::to_string(sub.quickestSec) + " in " + std::to_string(sub.quickestYear);
        if (&sub != &quickestSubmissions.back()) {
            factOne += ", ";
        }
    }

	facts[0] = factOne;

	std::vector<quickestFactStruct> quickestKnockouts = findQuickestKnockouts(allKo);
	
	std::string factTwo = "The quickest knockout was ";
	for (const auto& ko : quickestKnockouts) {
		factTwo += ko.quickestFirst + " " + ko.quickestLast + " at " + std::to_string(ko.quickestMin) + ":" +
			std::to_string(ko.quickestSec) + " in " + std::to_string(ko.quickestYear);
		if (&ko != &quickestKnockouts.back()) {
			factTwo += ", ";
		}
	}

	facts[1] = factTwo;



}
 std::vector<quickestFactStruct> findQuickestSubmissions(const std::vector<Submission>& allSub) {
	std::vector<quickestFactStruct> quickestSubmissions;	// vector to hold structs

	int minTime = std::numeric_limits<int>::max();	// flag set to highest int value
	int minSeconds = std::numeric_limits<int>::max();	// flag for seconds

	for (const auto& sub : allSub) {	
		if (sub.getMinute() < minTime || (sub.getMinute() == minTime && sub.getSeconds() < minSeconds)) {	// checks for lower min and sec
			minTime = sub.getMinute();	// adds the lower value
			minSeconds = sub.getSeconds();

			quickestFactStruct quickestStruct;	// instance of struct to hold new data
			quickestStruct.quickestMin = minTime;
			quickestStruct.quickestSec = minSeconds; 
			quickestStruct.quickestYear = sub.getYear();
			quickestStruct.quickestFirst = sub.getWinnerFirst();
			quickestStruct.quickestLast = sub.getWinnerLast();

			quickestSubmissions.clear(); // Clear previous quickest submissions
			quickestSubmissions.push_back(quickestStruct);
		}
		else if (sub.getMinute() == minTime && sub.getSeconds() == minSeconds) {	// validates data looking for a tie
			quickestFactStruct quickestStruct;
			quickestStruct.quickestMin = minTime;
			quickestStruct.quickestSec = minSeconds; 
			quickestStruct.quickestYear = sub.getYear();
			quickestStruct.quickestFirst = sub.getWinnerFirst();
			quickestStruct.quickestLast = sub.getWinnerLast();

			quickestSubmissions.push_back(quickestStruct);	// saves the tie instance
		}
	}

	return quickestSubmissions;
}
std::vector<quickestFactStruct> findQuickestKnockouts(const std::vector<Knockout>& allKo) {
	std::vector<quickestFactStruct> quickestKnockouts;  // vector to hold structs

	int minTime = std::numeric_limits<int>::max();  // flag set to highest int value
	int minSeconds = std::numeric_limits<int>::max();  // flag for seconds

	for (const auto& ko : allKo) {
		if (ko.getMinute() < minTime || (ko.getMinute() == minTime && ko.getSeconds() < minSeconds)) {
			minTime = ko.getMinute();  // adds the lower value
			minSeconds = ko.getSeconds();

			quickestFactStruct quickestStruct;  // instance of struct to hold new data
			quickestStruct.quickestMin = minTime;
			quickestStruct.quickestSec = minSeconds;
			quickestStruct.quickestYear = ko.getYear();
			quickestStruct.quickestFirst = ko.getWinnerFirst();
			quickestStruct.quickestLast = ko.getWinnerLast();

			quickestKnockouts.clear();  // Clear previous quickest knockouts
			quickestKnockouts.push_back(quickestStruct);
		}
		else if (ko.getMinute() == minTime && ko.getSeconds() == minSeconds) {
			quickestFactStruct quickestStruct;
			quickestStruct.quickestMin = minTime;
			quickestStruct.quickestSec = minSeconds;
			quickestStruct.quickestYear = ko.getYear();
			quickestStruct.quickestFirst = ko.getWinnerFirst();
			quickestStruct.quickestLast = ko.getWinnerLast();

			quickestKnockouts.push_back(quickestStruct);  // saves the tie instance
		}
	}

	return quickestKnockouts;
}








