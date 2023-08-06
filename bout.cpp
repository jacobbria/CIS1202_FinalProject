#include "Bout.h"
#include <iostream>

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
void  Bout::setWinnerFirst(const std::string& winnerfirst) {
	winnerFirst = winnerfirst;
}
void  Bout::setWinnerLast(const std::string& winnerlast) {
	winnerLast = winnerlast;
}
void  Bout::setLoserFirst(const std::string& loserfirst) {
	loserFirst = loserfirst;
}
void Bout::setLoserLast(const std::string& loserlast) {
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
	
	