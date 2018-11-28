//
//  Fanpage.hpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef Fanpage_hpp
#define Fanpage_hpp

#include "constants.hpp"
//#include "Member.hpp"
#include "Status.hpp"

class Member;
//class Status;

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
    //constructors
    Fanpage(char* name)
    {
        strcpy(this->name, name);
    }
    
    ~Fanpage()
    {
        if (fansCount != 0) {
            delete []fans;
        }
        if (statusesCount != 0) {
            for (int i = 0; i < statusesCount; i++) {
                delete statuses[i];
            }
            delete []statuses;
        }
    }
    
    bool        addFan(Member* fan);
    Member**    getFans()                   const;
    Status**    getStatuses()               const;
    char*       getName();
    bool        addStatus(Status* newStatus);
};

#endif /* Fanpage_hpp */
