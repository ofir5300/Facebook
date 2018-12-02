//
//  Date.hpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp

#include "constants.hpp"

class Date
{
private:
    // Attributes
    int day;
    int month;
    int year;
    char dateStr[11];  //format: dd/mm/yyyy
public:
    //constructors
    
    Date()
    {
        int nowDay, nowMonth, nowYear;
        
        time_t t = time(0);   // get time now
        tm* now = localtime(&t);
        
        nowDay = now->tm_mday;
        nowMonth = now->tm_mon + 1;
        nowYear = now->tm_year + 1900;
        
        Date(nowDay, nowMonth, nowYear);
    }
    
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        
        dateStr[0] = day/10;
        dateStr[1] = day%10;
        dateStr[2] = '/';
        dateStr[3] = month/10;
        dateStr[4] = month%10;
        dateStr[5] = '/';
        dateStr[6] = year / 1000;
        dateStr[7] = (year % 1000) / 100;
        dateStr[8] = (year % 100) / 10;
        dateStr[9] = year % 10;
        dateStr[10] = '\n';
    }
    
    Date(char* dateStr)
    {
        fixInput(dateStr);
        
        strcpy(this->dateStr, dateStr);
        
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
    int     getDay()        const   {return day;}
    int     getMonth()      const   {return month;}
    int     getYear()       const   {return year;}
    char*   getDateStr()       {return dateStr;}
    void    printDate()     const;
    char*   fixInput(char* dateStr);
};

#endif /* Date_hpp */
