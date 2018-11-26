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
    Date*       birthDate;
    Status**    statuses = nullptr;
    int         statusesCount = 0;
    int         statusesArrSize = 0;
    Member**    friends = nullptr;
    int         friendsCount = 0;
    int         friendsArrSize = 0;
    Fanpage**   fanPages = nullptr;
    int         fanPagesCount = 0;
    int         fanPagesArrSize = 0;
    
    
public:
    // Constructor, Distructor
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
            for(int i = 0 ; i < fanPagesCount; i++)
            {
                delete [] fanPages[i];
            }
            delete fanPages;
        }
        
        if(statusesCount != 0)    // != nullptr
        {
            for(int i = 0 ; i < statusesCount; i++)
            {
                delete [] statuses[i];
            }
            delete statuses;
        }
    }
    // Methods
    const Status**      getStatuses()            const;    // how shell we pass array of objects using ref
    int                 getStatusesCount();
    const Status**      getRecentStatuses()      const;    // using getStatuses() to fetch 10 recent statuses
    const Status**      fetchFriendsStatuses()   const;
    bool                addFriend(const Member* newFriend);
    bool                addFanPage(const Fanpage* newFanPage);
    Fanpage**           getFanPages()             const;
    Member**            getFriends()              const;
    char*               getName()                   const;
    Date*               getBirthDate()              const;
};





#endif /* Member_hpp */


















