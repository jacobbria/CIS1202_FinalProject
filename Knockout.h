#pragma once
#ifndef KNOCKOUT_H
#define KNOCKOUT_H

#include "Bout.h"
#include <iostream>

class Knockout : public Bout {
private:
	std::string knockoutTechnique;
	
public:
	Knockout();
	Knockout(std::string kot,std::string wc, std::string wf, std::string wl,
		std::string losF, std::string losL, int min, int sec, int rd, int yr);

	// setters
	void setKnockoutTechnique(std::string kot);

	// getters
	std::string getKnockoutTechnique();
};

#endif // KNOCKOUT_H
