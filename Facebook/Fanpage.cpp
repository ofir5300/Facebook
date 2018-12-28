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
    addConnection((Entity*)fan);
    fansCount++;
    return true;
}
