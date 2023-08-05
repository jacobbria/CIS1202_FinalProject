#pragma once
#ifndef KNOCKOUT.H
#define KNOCKOUT.H

#include "Bout.h";
#include <iostream>

class Knockout : public Bout {
private:
	std::string knockoutTechnique;
	
public:
	Knockout() : Bout() {	// default constrcutor
		knockoutTechnique = "";
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
	
	Knockout(std::string kot, std::string bt, std::string wc, std::string wf, std::string wl,
		std::string losF, std::string losL, int min, int sec, int rd, int yr) : Bout() {
		knockoutTechnique = kot;

	}

	// setters
	void setKnockoutTechnique(std::string kot) {
		knockoutTechnique = kot;
	}

	// getters
	std::string getKnockoutTechnique() {
		return knockoutTechnique;
	}
};

#endif // KNOCKOUT.H
