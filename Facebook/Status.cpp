//
//  Status.cpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#include "Status.hpp"


const Date& Status:: getDate() const
{
    return date;
}

const Time& Status:: getTime() const
{
    return time;
}

const enum Status:: getType() const
{
    return type;
}

const char* Status:: getContent() const
{
    return content;
}
