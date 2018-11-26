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
public:
    //constructors
    Date(char* dateStr)
    {
        //format dd/mm/yyyy
        //       0123456789
        
        fixInput(dateStr);
        
        day = dateStr[1] + '0';
        day += (dateStr[0] + '0') * 10;
        month = dateStr[4] + '0';
        month += (dateStr[3] + '0') * 10;
        year = dateStr[9] + '0';
        year += (dateStr[8] + '0') * 10;
        year += (dateStr[7] + '0') * 100;
        year += (dateStr[6] + '0') * 1000;
    }
    
    //methods
    int     getDay()        const   {return day;}
    int     getMonth()      const   {return month;}
    int     getYear()       const   {return year;}
    char*   getDateStr()    const;      ////////////////////
    char*   fixInput(char* dateStr);
};

#endif /* Date_hpp */
