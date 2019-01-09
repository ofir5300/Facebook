//
//  Date.hpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef __Date_h
#define __Date_h	

#include "constants.h"

class Date
{
private:
	// Attributes
	int day;
	int month;
	int year;
	//char dateStr[11];  //format: dd/mm/yyyy
	string dateStr;
public:
	//constructors

	Date()
	{
		//        int nowDay, nowMonth, nowYear;

		time_t t = time(0);   // get time now
		tm* now = localtime(&t);

		day = now->tm_mday;
		month = now->tm_mon + 1;
		year = now->tm_year + 1900;
		
		dateStr.reserve(11);
		dateStr.push_back((day / 10) + '0');
		dateStr.push_back((day % 10) + '0');
		dateStr.push_back('/');
		dateStr.push_back((month / 10) + '0');
		dateStr.push_back((month % 10) + '0');
		dateStr.push_back('/');
		dateStr.push_back((year / 1000) + '0');
		dateStr.push_back(((year % 1000) / 100) + '0');
		dateStr.push_back(((year % 100) / 10) + '0');
		dateStr.push_back((year % 10) + '0');
		dateStr.push_back('\0');

		/*
		dateStr.reserve(11);
		dateStr[0] = (char)(day / 10) + '0';
		dateStr[1] = (char)(day % 10) + '0';
		dateStr[2] = '/';
		dateStr[3] = (char)(month / 10) + '0';
		dateStr[4] = (char)(month % 10) + '0';
		dateStr[5] = '/';
		dateStr[6] = (char)(year / 1000) + '0';
		dateStr[7] = (char)((year % 1000) / 100) + '0';
		dateStr[8] = (char)((year % 100) / 10) + '0';
		dateStr[9] = (char)(year % 10) + '0';
		dateStr[10] = '\0';
		*/
		//        Date(nowDay, nowMonth, nowYear);
	}


	Date(string& dateStr)
	{
		fixInput(dateStr);

		//strcpy(this->dateStr, dateStr);
		this->dateStr = dateStr;

		day = dateStr[1] - '0';
		day += (dateStr[0] - '0') * 10;
		month = dateStr[4] - '0';
		month += (dateStr[3] - '0') * 10;
		year = dateStr[9] - '0';
		year += (dateStr[8] - '0') * 10;
		year += (dateStr[7] - '0') * 100;
		year += (dateStr[6] - '0') * 1000;
	}

	//methods
	int     getDay()        const { return day; }
	int     getMonth()      const { return month; }
	int     getYear()       const { return year; }
	string&   getDateStr() { return dateStr; }
	void    printDate()     const;
	string&   fixInput(string& dateStr);
	int     compare(Date* other);
};

#endif /* Date_h */
