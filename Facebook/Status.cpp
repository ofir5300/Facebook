//
//  Status.cpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#include "Status.hpp"

const char* Status:: getContent() const
{
    return content;
}

void Status:: printStatus() const                           
{
    cout << "Status posted on " << date->getDateStr() << " " << time->getTimeStr() << "\n[" << typeNames[(int)contentType + 1] << "] : " << content;
}

int Status::compare(Status* other)
{
    int resultByDate = this->date->compare(other->date);
    int resultByTime = this->time->compare(other->time);
    
    if (resultByDate == 0)
        return resultByTime;
    return resultByDate;
}









