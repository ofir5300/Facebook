//
//  Time.hpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef __Time_h
#define __Time_h

#include "constants.h"

class Time
{
private:
	// Attributes
	int     hours;//= 0;
	int     minutes;//= 0;
	int     seconds;//= 0;
	char    timeStr[9] = { 0 };

public:
	// Constructors
	Time()
	{
		//        int nowHours, nowMinutes, nowSeconds;

		time_t t = time(0);   // get time now
		tm* now = localtime(&t);

		hours = now->tm_hour;
		minutes = now->tm_min;
		seconds = now->tm_sec;

		timeStr[0] = hours / 10 + '0';
		timeStr[1] = hours % 10 + '0';
		timeStr[2] = ':';
		timeStr[3] = minutes / 10 + '0';
		timeStr[4] = minutes % 10 + '0';
		timeStr[5] = ':';
		timeStr[6] = seconds / 10 + '0';
		timeStr[7] = seconds % 10 + '0';
		timeStr[8] = '\0';
		//        Time(nowHours, nowMinutes, nowSeconds);
	}


	// Methods
	int     getHours()      const { return hours; }
	int     getMinutes()    const { return minutes; }
	int     getSeconds()    const { return seconds; }
	char*   getTimeStr() { return timeStr; }
	void    printTime()     const;
	int     compare(Time* other);
};

#endif /* Time_h */
