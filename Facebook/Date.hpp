//
//  Date.hpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>

class Date
{
private:
    // Attributes
    int day;
    int month;
    int year;
public:
    // Methods
    int     getDay()        const;
    int     getMonth()      const;
    int     getYear()       const;
    char*   getDateStr()    const;
};

#endif /* Date_hpp */
