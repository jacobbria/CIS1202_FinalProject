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

Submission::Submission(std::string st, submissionPosition sp, std::string wc, std::string wf, std::string wl,
	std::string losF, std::string losL, int min, int sec, int rd, int yr) :Bout() {
	submissionType = st;
	position = sp;
}

// setters
void Submission::setSubmissionType(std::string& st) {
	capitalizeAllLetters(st);
	submissionType = st;
}
void Submission::setPosition(int posInt) {
	position = static_cast<Submission::submissionPosition>(posInt);
}

// getters
std::string Submission::getSubmissionType() const {
	return submissionType;
}
Submission::submissionPosition Submission::getPosition() const {
	return position;
}
std::string Submission::getpositionToString() const {
	switch (position) {
	case GUARD: return "GUARD";
	case MOUNT: return "MOUNT";
	case BACK: return "BACK";
	case TOPSIDE: return "TOP SIDE";
	case BOTTOMSIDE: return "BOTTOM SIDE";
	case STANDING: return "STANDING";
	case OTHER: return "OTHER";
	default: return "UNKNOWN";
	}
}

