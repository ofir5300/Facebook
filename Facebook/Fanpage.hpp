//
//  Fanpage.hpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef Fanpage_hpp
#define Fanpage_hpp

#include <iostream>
#include "constants.hpp"
#include "Member.hpp"
#include "Status.hpp"

using namespace std;

class Fanpage
{
private:
    char        name[NAME_MAX_SIZE];
    Member**    fans = nullptr;
    int         fansCount = 0;
    int         fansArrSize = 0;
    Status**    statuses = nullptr;
    int         statusesCount = 0;
    int         statusesArrSize =0;
    
public:
    bool        addFan(const Member& fan);
    Member**    getFans()                   const;
    Status**    getStatuses()               const;
    char*       getName()                   const;
};

#endif /* Fanpage_hpp */
