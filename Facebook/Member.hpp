//
//  Member.hpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef Member_hpp
#define Member_hpp

#include "Date.hpp"
#include "Time.hpp"
#include "Status.hpp"
#include "Fanpage.hpp"

class Member
{
private:
    //attributes
    char        name[NAME_MAX_SIZE];
    Date*        birthDate;
    Status**    statuses = nullptr;
    Member**    friends = nullptr;
    int         friendsCount = 0;
    int         friendsArrSize = 0;
    Fanpage**   fanPages = nullptr;
    int         fanPagesCount = 0;
    int         fanPageArrSize = 0;
    
    
public:
    //constructor
    Member(char* name, Date birthDate)
    {
        strcpy(this->name, name);
        this->birthDate = &birthDate;
    }
    
    ~Member()
    {
        if(friendsCount != 0)
        {
            for(int i = 0 ; i < friendsCount; i++)
            {
                delete [] friends[i];
            }
            delete friends;
            
        }
        
        if(fanPagesCount != 0)
        {
            
            
        }
        
        if(statuses)    // != nullptr
        {
            
        }
    }
    //methods
    const Status**      getStatuses()            const;    // how shell we pass array of objects using ref
    const Status**      getRecentStatuses()      const;    // using getStatuses() to fetch 10 recent statuses
    const Status**      fetchFriendsStatuses()   const;
    bool                addFriend();
    bool                addFanPage();
    Fanpage**           getFanPages()             const;
    Member**            getFriends()              const;
    char*               getName()                   const;
    Date&               getBirthDate()              const;
    Status**            getFriensRecentStatuses()   const;
};





#endif /* Member_hpp */


















