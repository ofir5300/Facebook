//
//  Member.cpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#include "Member.hpp"
  
const Status** Member:: getStatuses() const
{
    return (const Status**)statuses;
}

const Status** Member:: getRecentStatuses() const
{
    Status** recent = new Status* [10];
    for(int i = 0 ; i < 10 ; i++)
    {
        recent[i] = statuses[i];
    }
    
    return (const Status**)recent;
}

const Status** Member:: fetchFriendsStatuses() const
{
    
}
bool Member:: addFriend()
{
    
}
bool                addFanPage();
Fanpage**           getFanPages()           const;
Member**            getFriends()            const;
char*               getName()               const;
Date&               getBirthDate();
Status**            getFriensRecentStatuses;
