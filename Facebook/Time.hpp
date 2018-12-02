//
//  Time.hpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp

#include "constants.hpp"

class Time
{
private:
    // Attributes
    int     hours ;//= 0;
    int     minutes ;//= 0;
    int     seconds ;//= 0;
    char    timeStr[9];
    
public:
    // Constructors
    Time()
    {
        int nowHours, nowMinutes, nowSeconds;
        
        time_t t = time(0);   // get time now
        tm* now = localtime(&t);
        
        nowHours = now->tm_hour;
        nowMinutes = now->tm_min;
        nowSeconds = now->tm_sec;
        
        Time(nowHours, nowMinutes, nowSeconds);
    }
    
    Time(int hours, int minutes, int seconds)
    {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;

        timeStr[0] = hours / 10;
        timeStr[1] = hours % 10;
        timeStr[2] = ':';
        timeStr[3] = minutes / 10;
        timeStr[4] = minutes % 10;
        timeStr[5] = ':';
        timeStr[6] = seconds / 10;
        timeStr[7] = seconds % 10;
        timeStr[8] = '\n';
    }
    
    // Methods
    int     getHours()      const   {return hours;}
    int     getMinutes()    const   {return minutes;}
    int     getSeconds()    const   {return seconds;}
    char*   getTimeStr()            {return timeStr;}
    void    printTime()     const;
};

#endif /* Time_hpp */
