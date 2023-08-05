#pragma once
#ifndef SUBMISSION.H
#define SUBMISSION.H

#include "Bout.h"	// parent class included
#include <iostream>


// This is a child class of Bout.h
// A Bout that ends with a Submission

class Submission : public Bout {

	enum submissionPosition {GUARD, MOUNT, BACK, TOPSIDE, BOTTOMSIDE, STANDING, OTHER};	// options for position where submission was hit from

private:
	std::string submissionType;	// name of submission
	submissionPosition position; // position of submission

public:
	Submission() :Bout() {	// default constructor
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

	Submission(std::string st, submissionPosition sp, std::string bt, std::string wc, std::string wf, std::string wl,
		std::string losF, std::string losL, int min, int sec, int rd, int yr) :Bout() {
		submissionType = st;
		position = sp;
	
	}

	// setters
	void setSubmissionType(std::string st) {
		submissionType = st;
	}
	void setPosition(submissionPosition sp) {
		position = sp;
	}

	// getters
	std::string getSubmissionType() {
		return submissionType;
	}
	submissionPosition getPosition() {
		return position;
	}









};











#endif // !SUBMISSION.H

