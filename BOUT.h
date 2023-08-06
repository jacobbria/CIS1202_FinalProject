#pragma once
#ifndef BOUT_H
#define BOUT_H

#include <iostream>
#include <string>

// This Header class file for the parents class to subsequent bouts with specific finish types

class Bout
{

protected:
	std::string boutTitle;	// will be winnerLast + loserLast... ex. "Smith v Brown"
	std::string weightClass;
	std::string winnerFirst;
	std::string winnerLast;
	std::string loserFirst;
	std::string loserLast;
	std::string timeClock;
	int minute;
	int seconds;
	int round;
	int year;	// year bout occured in


public:
	Bout();

	Bout(std::string wc, std::string wf, std::string wl,
		std::string losF, std::string losL, int min, int sec, int rd, int yr);
	
	// setter prototypes
	void setWeightClass(const std::string& weightclass);
	void setWinnerFirst(std::string& winnerfirst);
	void setWinnerLast(std::string& winnerlast);
	void setLoserFirst(std::string& loserfirst);
	void setLoserLast(std::string& loserlast);
	void setTimeClock(int minute, int seconds);
	void setMinute(int min);
	void setSeconds(int sec);
	void setRound(int rd);
	void setYear(int yr);


	// getter prototypes
	std::string getBoutTitle() const;
	std::string getWeightClass() const;
	std::string getWinnerFirst() const;
	std::string getWinnerLast() const;
	std::string getLoserFirst() const;
	std::string getLoserLast() const;
	std::string getTimeClock();
	int getMinute() const;
	int getSeconds() const;
	int getRound() const;
	int getYear() const;
	
	// ensure proper name grammar
	void capitalizeFirstLetter(std::string& str);
};

#endif BOUT_H
