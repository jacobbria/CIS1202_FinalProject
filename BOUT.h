#pragma once
#ifndef BOUT.H
#define BOUT.H

#include <iostream>
#include <string>

// This class is the parents class to subsequent bouts with specific finish types
class Bout
{

private:
	std::string boutTitle;	// will be winnerLast + loserLast... ex. "Smith v Brown"
	std::string weightClass;
	std::string winnerFirst;
	std::string winnerLast;
	std::string loserFirst;
	std::string loserLast;
	int minute;
	int seconds;
	int round;
	int year;	// year bout occured in

public:
	Bout() {	// default constructor
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

	Bout(std::string bt, std::string wc, std::string wf, std::string wl, 
		std::string losF, std::string losL, int min, int sec, int rd, int yr) {

		boutTitle = bt;
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
	void setBoutTitle(const std::string& title) {
		boutTitle = title;
	}
	void setWeightClass(const std::string& weightclass) {
		weightClass = weightclass;
	}
	void setWinnerFirst(const std::string& winnerfirst) {
		winnerFirst = winnerfirst;
	}
	void setWinnerLast(const std::string& winnerlast) {
		winnerLast = winnerlast;
	}
	void setLoserFirst(const std::string& loserfirst) {
		loserFirst = loserfirst;
	}
	void setMinute(int min) {
		minute = min;
	}
	void setSeconds(int sec) {
		minute = sec;
	}
	void setRound(int rd) {
		minute = rd;
	}
	void setYear(int yr) {
		minute = yr;
	}

	// getters

	std::string getBoutTitle() const {
		return boutTitle;
	}
	std::string getWeightClass() const {
		return weightClass;
	}
	std::string getWinnerFirst() const {
		return winnerFirst;
	}
	std::string getWinnerLast() const {
		return winnerLast;
	}
	std::string getLoserFirst() const {
		return loserFirst;
	}
	std::string getLoserLast() const {
		return loserLast;
	}
	int getMinute() const {
		return minute;
	}
	int getSeconds() const {
		return seconds;
	}
	int getRound() const {
		return round;
	}
	int getYear() const {
		return year;
	}

};











#endif
