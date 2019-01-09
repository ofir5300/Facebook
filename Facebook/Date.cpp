//
//  Date.cpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#include "Date.h"

string& Date::fixInput(string& dateStr)  //format: dd/mm/yyyy
{
	int day, month, year, length, badInput = 0;

	do {
		day = dateStr[1] - '0';
		day += (dateStr[0] - '0') * 10;
		month = dateStr[4] - '0';
		month += (dateStr[3] - '0') * 10;
		year = dateStr[9] - '0';
		year += (dateStr[8] - '0') * 10;
		year += (dateStr[7] - '0') * 100;
		year += (dateStr[6] - '0') * 1000;

		length = (int)dateStr.size();
		//length = (int)strlen(dateStr);

		if (length != 10 ||
			dateStr[2] != '/' ||
			dateStr[5] != '/')
		{
			cout << "Please enter a date in the following format: \"dd/mm/yyyy\"\n";
			cin >> dateStr;
			badInput = 1;
		}
		else if (day > 31 || day < 1 ||
			month > 12 || month < 1 ||
			year < 0 || year > 9999)
		{
			cout << "Please enter a date with legal numbers\n";
			cin >> dateStr;
			badInput = 1;
		}
		else
		{
			badInput = 0;
			return dateStr;
		}

	} while (badInput);

	return dateStr;
}

void Date::printDate() const
{
	cout << dateStr;
}


int Date::compare(Date* other)
{
	if (this->year > other->year)
		return 1;
	else if (this->year < other->year)
		return -1;
	else if (this->month > other->month)
		return 1;
	else if (this->month < other->month)
		return -1;
	else if (this->day > other->day)
		return 1;
	else if (this->day < other->day)
		return -1;

	return 0;
}
