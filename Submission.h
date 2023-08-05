#pragma once
#ifndef SUBMISSION_H
#define SUBMISSION_H

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
	// child prototypes
	Submission();
	Submission(std::string st, submissionPosition sp, std::string bt, std::string wc, std::string wf, std::string wl,
		std::string losF, std::string losL, int min, int sec, int rd, int yr);

	// setters
	void setSubmissionType(std::string st);
	void setPosition(submissionPosition sp);

	// getters
	std::string getSubmissionType() const;
	submissionPosition getPosition() const;
};











#endif // !SUBMISSION_H

