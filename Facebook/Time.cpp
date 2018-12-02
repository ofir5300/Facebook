//
//  Time.cpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#include "Time.hpp"


void Time::printTime() const
{
    cout << timeStr;
}

int Time::compare(Time* other)
{
    if (this->hours > other->hours)
        return 1;
    else if (this->hours < other->hours)
        return -1;
    else if (this->minutes > other->minutes)
        return 1;
    else if (this->minutes < other->minutes)
        return -1;
    else if (this->seconds > other->seconds)
        return 1;
    else if (this->seconds < other->seconds)
        return -1;
    
    return 0;
}
