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
	int minute;
	int seconds;
	int round;
	int year;	// year bout occured in

public:
	Bout();

	Bout(std::string bt, std::string wc, std::string wf, std::string wl,
		std::string losF, std::string losL, int min, int sec, int rd, int yr);
	
	// setter prototypes
	void setBoutTitle(const std::string& title);
	void setWeightClass(const std::string& weightclass);
	void setWinnerFirst(const std::string& winnerfirst);
	void setWinnerLast(const std::string& winnerlast);
	void setLoserFirst(const std::string& loserfirst);
	void setLoserLast(const std::string& loserlast);
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
	int getMinute() const;
	int getSeconds() const;
	int getRound() const;
	int getYear() const;

};

#endif BOUT_H
