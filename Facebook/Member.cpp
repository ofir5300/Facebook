//
//  Member.cpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#include "Member.hpp"

Status** Member:: getStatuses() const
{
    return statuses;
}

int Member:: getStatusesCount()
{
    return statusesCount;
}

Status** Member:: getRecentStatuses() const
{   // retruns an array of 10 last statuses, or all statuses if less than 10
    Status** recent = new Status* [(RECENT_STATUSES > statusesCount) ? RECENT_STATUSES : statusesCount];
    for(int i = 0 ; i < RECENT_STATUSES && i < statusesCount ; i++)
    {
        recent[i] = statuses[i];
    }
    
    return recent;
}



Status** Member::getAllFriendsRecentStatuses() const
{
    Status* MostRecentStatusTempPtr = nullptr;
    int i, j, currRecentIndex = 0, compareResult;
    
    // creating friend's statuses indices tracking
    int* statusIndices = new int(friendsCount);
    for (i = 0; i < friendsCount; i++)
        statusIndices[i] = friends[i]->getStatusesCount() -1;
    
    // initialising recent statuses arr
    Status** recentStatuses = new Status* [RECENT_STATUSES];
    for (i = 0; i < RECENT_STATUSES; i++)
        recentStatuses[i] = nullptr;
    
    // [ 3 | -1 | 2 | 0 ]

      for (i = 0; i < RECENT_STATUSES; i++) {
        MostRecentStatusTempPtr = nullptr;
        for (j = 0; j < friendsCount; j++) {
            if (statusIndices[j] != -1 && MostRecentStatusTempPtr == nullptr)
            {
                MostRecentStatusTempPtr = friends[j]->getStatuses()[statusIndices[j]];
                currRecentIndex = j;
            }
            else if (statusIndices[j] != -1)
            {
                compareResult = MostRecentStatusTempPtr->compare(friends[j]->getStatuses()[statusIndices[j]]);
                
                if (compareResult == -1) {
                    MostRecentStatusTempPtr = friends[j]->getStatuses()[statusIndices[j]];
                    currRecentIndex = j;
                }
            }
        }
        
        if (MostRecentStatusTempPtr != nullptr)
        {
            recentStatuses[i] = MostRecentStatusTempPtr;
            statusIndices[currRecentIndex] --;
        }
    }
    
    if (recentStatuses[0] == nullptr) {
        cout << "No statuses\n";
        return nullptr;
    }
    
    delete statusIndices;
    return recentStatuses;
}


Status* Member::getMostRecentStatus()
{
    return (statuses == nullptr)? nullptr : statuses[statusesCount - 1];
}

Status** Member:: fetchFriendsStatuses() const
{   // returns an array of all friends recent statuses (10 or less for each)
    int size = 0;
    for(int i = 0 ; i < friendsCount ; i++)
        size += friends[i]->getStatusesCount();
    
    
    Status** friendsStatuses = new Status* [size];
    int counter = 0;
    
    for(int i = 0 ; i < friendsCount; i++)
    {
        Status** recent = friends[i]->getRecentStatuses();
        for(int j = 0 ; j < RECENT_STATUSES && j < friends[i]->getStatusesCount(); j++)
        {
            friendsStatuses[counter++] =  recent[j];
        }
    }
    return friendsStatuses;
}
        
bool Member:: addFriend(Member* newFriend)
{   // add an new member to 'friends' array
    
    if(!friendsCount)   // if array is empty
    {
        friendsArrSize = INITIAL_ARR_DYNAMIC_SIZE;
        friends = new Member* [friendsArrSize];
    }
    else if (friendsCount == friendsArrSize && friendsCount != 0)
    {
        Member** temp = friends;
        friendsArrSize *= 2;
        friends = new Member*[friendsArrSize];
        memcpy(friends, temp, sizeof(Member*) * friendsCount);
    }
    
    friends[friendsCount++] = newFriend;
    return true;
}
        
bool Member:: addFanPage(Fanpage* newFanPage)
{
    if(!fanPagesCount)
    {
        fanPagesArrSize = INITIAL_ARR_DYNAMIC_SIZE;
        fanPages = new Fanpage* [fanPagesArrSize];
    }
    else if(fanPagesCount == fanPagesArrSize && fanPagesCount != 0)
    {
        Fanpage** temp = fanPages;
        fanPagesArrSize *= 2;
        fanPages = new Fanpage* [fanPagesArrSize];
        memcpy(fanPages, temp, sizeof(Fanpage*) * fanPagesCount);
    }
    
    fanPages[fanPagesCount++] = newFanPage;
    return true;
}
        
Fanpage** Member:: getFanPages() const
{
    return fanPages;
}

Member**  Member:: getFriends() const
{
    return friends;
}

char* Member:: getName()
{
    return name;
}
        
Date* Member:: getBirthDate() const
{
    return birthDate;
}


void Member:: printMember() const
{
    cout << "\nMember Name: " << name << "\n"
    << "Birth Date: " << birthDate->getDateStr() << "\n";
}

bool Member::addStatus(Status* newStatus)
{
    if (statuses == nullptr) {
        statuses = new Status* [INITIAL_ARR_DYNAMIC_SIZE];
        statusesArrSize = INITIAL_ARR_DYNAMIC_SIZE;
        statusesCount = 0;
    }
    else if (statusesCount == statusesArrSize)
    {
        Status** temp = statuses;
        statusesArrSize *= 2;
        statuses = new Status* [statusesArrSize];
        memcpy(statuses, temp, sizeof(Status*) * statusesCount);
        delete temp;
    }
    
    statuses[statusesCount++] = newStatus;
    return true;
}




