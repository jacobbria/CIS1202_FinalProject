#include "Bout.h"
#include <iostream>
#include <cctype>

// Implementation page of Bout.h header file

Bout::Bout() {	// default constructor
	
	weightClass = "";
	winnerFirst = "";
	winnerLast = "";
	loserFirst = "";
	loserLast = "";
	minute = 0;
	seconds = 0;
	year = 0;
}

Bout::Bout(std::string wc, std::string wf, std::string wl,
	std::string losF, std::string losL, int min, int sec, int rd, int yr) {

	weightClass = wc;
	winnerFirst = wf;
	winnerLast = wl;
	loserFirst = losF;
	loserLast = losL;
	minute = min;
	seconds = sec;
	year = yr;

}

// setters
void  Bout::setWeightClass(const std::string& weightclass) {
	weightClass = weightclass;
}
void Bout::setWinnerFirst(std::string& winnerfirst) {
	capitalizeFirstLetter(winnerfirst);
	winnerFirst = winnerfirst;
}

void Bout::setWinnerLast(std::string& winnerlast) {
	capitalizeFirstLetter(winnerlast);
	winnerLast = winnerlast;
}

void Bout::setLoserFirst(std::string& loserfirst) {
	capitalizeFirstLetter(loserfirst);
	loserFirst = loserfirst;
}

void Bout::setLoserLast(std::string& loserlast) {
	capitalizeFirstLetter(loserlast);
	loserLast = loserlast;
}
void Bout::setTimeClock(int minute, int seconds) {
	timeClock = std::to_string(minute) + ":" + std::to_string(seconds);
}
void  Bout::setMinute(int min) {
	minute = min;
}
void  Bout::setSeconds(int sec) {
	seconds = sec;
}
void  Bout::setRound(int rd) {
	round = rd;
}
void Bout::setYear(int yr) {
	year = yr;
}


// getters
	std::string Bout::getBoutTitle() const {
		return winnerLast + " vs " + loserLast;
	}
	std::string Bout::getWeightClass() const {
		return weightClass;
	}
	std::string Bout::getWinnerFirst() const {
		return winnerFirst;
	}

	std::string Bout::getWinnerLast() const {
		return winnerLast;
	}

	std::string Bout::getLoserFirst() const {
		return loserFirst;
	}

	std::string Bout::getLoserLast() const {
		return loserLast;
	}
	std::string Bout::getTimeClock() {
		return timeClock;
	}
	int Bout::getMinute() const {
		return minute;
	}
	int Bout::getSeconds() const {
		return seconds;
	}
	int Bout::getRound() const {
		return round;
	}
	int Bout::getYear() const {
		return year;
	}
	
	// Ensure proper name grammar
	void Bout::capitalizeFirstLetter(std::string& str) {
		if (!str.empty()) {
			str[0] = std::toupper(str[0]);
			for (size_t i = 1; i < str.length(); ++i) {
				str[i] = std::tolower(str[i]);
			}
		}
	}

	// capitalize all letters
	void Bout::capitalizeAllLetters(std::string& str) {
		for (char& c : str) {
			c = std::toupper(c);  // Convert each character to uppercase
		}
	}

	