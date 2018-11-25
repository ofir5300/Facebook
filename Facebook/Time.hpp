//
//  Time.hpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>

class Time
{
private:
    //attributes
    int     minutes = 0;
    int     hours = 0;
    
public:
    //methods
    int     getMinutes()    const;
    int     getHours()      const;
    char*   getTimeStr()    const;
};

#endif /* Time_hpp */
