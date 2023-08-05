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

std::vector<Bout> combineAllBouts(std::vector<Submission>& allSubmissions, std::vector<Knockout>& allKnockouts);

int main()
{
	std::vector<Bout> allBouts;	// vector to hold both submission and knockout finished bouts
	std::vector<Submission> allSubmissions; // vector to store all submission ended bouts
	std::vector<Knockout> allKnockouts; // vector to store all knockout ended bouts

	allBouts = combineAllBouts(allSubmissions, allKnockouts);	// combine submission and KO vectors into allBouts





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
