#include "Submission.h"
#include <iostream>

// Implementation of child class Submission

Submission::Submission() :Bout() {	// default constructor
	submissionType = "";
	position = OTHER;
	boutTitle = "";
	weightClass = "";
	winnerFirst = "";
	winnerLast = "";
	loserFirst = "";
	loserLast = "";
	minute = 0;
	seconds = 0;
	year = 0;
}

Submission::Submission(std::string st, submissionPosition sp, std::string bt, std::string wc, std::string wf, std::string wl,
	std::string losF, std::string losL, int min, int sec, int rd, int yr) :Bout() {
	submissionType = st;
	position = sp;
}

// setters
void Submission::setSubmissionType(const std::string st) {
	submissionType = st;
}
void Submission::setPosition(submissionPosition sp) {
	position = sp;
}

// getters
std::string Submission::getSubmissionType() const {
	return submissionType;
}
Submission::submissionPosition Submission::getPosition() const {
	return position;
}

