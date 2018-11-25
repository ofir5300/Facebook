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
    Status** recent = new Status* [RECENT_STATUSES];
    for(int i = 0 ; i < RECENT_STATUSES ; i++)
    {
        recent[i] = statuses[i];
    }
    
    return (const Status**)recent;
}

const Status** Member:: fetchFriendsStatuses() const
{
    Status** friendsStatuses = new Status* [RECENT_STATUSES * friendsCount];
    int counter = 0;
    
    for(int i = 0 ; i < friendsCount; i++)
    {
        for(int j = 0 ; j < RECENT_STATUSES; j++)
        {
            friendsStatuses[counter] = new Status;
            friendsStatuses[counter++] = (friends[i]->getRecentStatuses())[j];
            
        }
    }
    
}
        
bool Member:: addFriend()
{
    
}
        
bool Member:: addFanPage()
{
    
}
        
Fanpage** Member:: getFanPages() const
{

}

Member**  Member:: getFriends() const
{
    
}

char* Member:: getName() const
{
    
}
        
Date& Member:: getBirthDate() const
{

}
        
Status** Member:: getFriensRecentStatuses() const
{
    
}













