//
//  Fanpage.cpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright � 2018 Ilan Kushnir. All rights reserved.
//

#include "Fanpage.h"

bool Fanpage::addFan(Member* fan)
{
    if (fans == nullptr) {
        fans = new Member*[INITIAL_ARR_DYNAMIC_SIZE];
        fansArrSize = INITIAL_ARR_DYNAMIC_SIZE;
        fansCount = 0;
    }
    else if (fansCount == fansArrSize)
    {
        Member** temp = fans;
        fansArrSize *= 2;
        fans = new Member*[fansArrSize];
        memcpy(fans, temp, sizeof(Member*) * fansCount);
        delete[]temp;
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


int Fanpage::getStatusesCount() const
{
    return statusesCount;
}

int Fanpage::getFansCount()
{
    return fansCount;
}

void Fanpage::printFanpage() const
{
    cout << "\nFanpage name: " << name << "\n";
}




bool Fanpage::addStatus(Status* newStatus)
{
    if (statuses == nullptr) {
        statuses = new Status*[INITIAL_ARR_DYNAMIC_SIZE];
        statusesArrSize = INITIAL_ARR_DYNAMIC_SIZE;
        statusesCount = 0;
    }
    else if (statusesCount == statusesArrSize)
    {
        Status** temp = statuses;
        statusesArrSize *= 2;
        statuses = new Status*[statusesArrSize];
        memcpy(statuses, temp, sizeof(Status*) * statusesCount);
        delete temp;
    }
    
    statuses[statusesCount++] = newStatus;
    return true;
}
