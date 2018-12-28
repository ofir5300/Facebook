//
//  Fanpage.h
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright � 2018 Ilan Kushnir. All rights reserved.
//

#ifndef __Fanpage_h
#define __Fanpage_h

#include "Entity.h"
#include "constants.h"
/////////////////
#include "Status.h"
#include "Date.h"
#include "Time.h"

class Member;
class Status;

using namespace std;

class Fanpage   : public Entity
{
private:
    int         fansCount = 0;

public:
    //constructors
    Fanpage(char* name) :Entity(name) {}
    virtual bool addFan(Member* fan);

};

#endif /* Fanpage_h */
