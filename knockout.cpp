#include "Knockout.h"
#include <iostream>

Knockout::Knockout() : Bout() {	// default constrcutor
	knockoutTechnique = "";
	weightClass = "";
	winnerFirst = "";
	winnerLast = "";
	loserFirst = "";
	loserLast = "";
	minute = 0;
	seconds = 0;
	year = 0;
}

Knockout::Knockout(std::string kot,std::string wc, std::string wf, std::string wl,
	std::string losF, std::string losL, int min, int sec, int rd, int yr) : Bout() {
	
	knockoutTechnique = kot;

}

// setters
void Knockout::setKnockoutTechnique(std::string kot) {
	knockoutTechnique = kot;
}

//getters
std::string Knockout::getKnockoutTechnique() {
	return knockoutTechnique;
}