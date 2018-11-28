//
//  Fanpage.cpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#include "Fanpage.hpp"

bool Fanpage::addFan(Member* fan)
{
    if (fans == nullptr) {
        fans = new Member* [INITIAL_ARR_DYNAMIC_SIZE];
        fansArrSize = INITIAL_ARR_DYNAMIC_SIZE;
        fansCount = 0;
    }
    else if (fansCount == fansArrSize)
    {
        Member** temp = fans;
        fansArrSize *= 2;
        fans = new Member* [fansArrSize];
        memcpy(fans, temp, sizeof(Member*) * fansCount);
        delete []temp;
    }
    
    fans[fansCount++] = fan;
    return true;
}

Member** Fanpage::getFans() const
{
    return fans;
}

Status** Fanpage::getStatuses() const
{
    return statuses;
}

char* Fanpage::getName()
{
    return name;
}
