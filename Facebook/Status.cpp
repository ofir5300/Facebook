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

void Status:: printStatus() const                           ///////////////////
{
    cout << "Status posted on " ;
    date->printDate();
    cout << " " ;
    time->printTime();
    cout << "\n[" << typeNames[(int)contentType - 1] << "] : " << content << "\n";
}











