//
//  Member.cpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright � 2018 Ilan Kushnir. All rights reserved.
//

#include "Member.h"

int Member::getFriendsCount()
{
    return friendsCount;
}

Status** Member::getAllFriendsRecentStatuses() const
{
        Status* MostRecentStatusTempPtr = nullptr;
        int i, j, currRecentIndex = 0, compareResult, arrIndex = 0;
    
        // creating friend's statuses indices tracking
        int* statusIndices = new int(friendsCount);
        int* membersInd = new int(friendsCount);
        for (i = 0; i < connectionsCount && arrIndex < friendsCount; i++)
            if(typeid(*(connections[i])) == typeid(Member))
            {
                membersInd[arrIndex] = i;
                statusIndices[arrIndex++] = (connections[i]->getStatusesCount()) - 1;
            }
    
        // initialising recent statuses arr
        Status** recentStatuses = new Status*[RECENT_STATUSES];
        for (i = 0; i < RECENT_STATUSES; i++)
            recentStatuses[i] = nullptr;
    
        // [ 3 | -1 | 2 | 0 ]
    
        for (i = 0; i < RECENT_STATUSES; i++) {
            MostRecentStatusTempPtr = nullptr;
            for (j = 0; j < friendsCount; j++) {
                if (statusIndices[j] != -1 && MostRecentStatusTempPtr == nullptr)
                {   // point on friend 'j' recent status if no status pointed yet
                    MostRecentStatusTempPtr = connections[membersInd[j]]->getStatuses()[statusIndices[j]];
                    currRecentIndex = j;
                }
                else if (statusIndices[j] != -1)
                {   // compare pointed status with friends 'j; recent one
                    compareResult = MostRecentStatusTempPtr->compare(connections[membersInd[j]]->getStatuses()[statusIndices[j]]);
    
                    if (compareResult == -1)
                    { // if friend 'j' status is newer than the current pointed status
                        MostRecentStatusTempPtr = connections[membersInd[j]]->getStatuses()[statusIndices[j]];
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
            // if there are no friends to this member or no statuses for existing friends
            return nullptr;
        }
    
        return recentStatuses;
}

//Status** Member::fetchFriendsStatuses() const
//{   // returns an array of all friends recent statuses (10 or less for each)
//        int size = 0;
//        for (int i = 0; i < friendsCount; i++)
//            size += friends[i]->getStatusesCount();
//
//
//        Status** friendsStatuses = new Status*[size];
//        int counter = 0;
//
//        for (int i = 0; i < friendsCount; i++)
//        {
//            Status** recent = friends[i]->getRecentStatuses();
//            for (int j = 0; j < RECENT_STATUSES && j < friends[i]->getStatusesCount(); j++)
//            {
//                friendsStatuses[counter++] = recent[j];
//            }
//        }
//        return friendsStatuses;
//    return nullptr;
//}

bool Member::addFriend(Member* newFriend)
{
    addConnection(newFriend);
    friendsCount++;
    
    return true;
}

bool Member::addFanPage(Fanpage* newFanPage)
{
    addConnection((Entity*)newFanPage);
    fanPagesCount++;
    
    return true;
}

Fanpage** Member::getFanPages() const
{
    Fanpage** fanPages = (fanPagesCount)? new Fanpage*[fanPagesCount] : nullptr;
    int counter = 0;
    
    for (int i=0; (i < connectionsCount) && (counter < fanPagesCount); i++) {
        Entity* currConnection = connections[i];
        if (currConnection && (typeid(*currConnection) == typeid(Fanpage))) {
            fanPages[counter++] = (Fanpage*)connections[i];
        }
    }
    
    return fanPages;
}

Member**  Member::getFriends() const
{
    Member** friends = (friendsCount)? new Member*[friendsCount] : nullptr;
    int counter = 0;
    
    for (int i=0; (i < connectionsCount) && (counter < friendsCount); i++) {
        Entity* currConnection = connections[i];
        if (currConnection && (typeid(*currConnection) == typeid(Member))) {
            friends[counter++] = (Member*)connections[i];
        }
    }
    
    return friends;
}

Date* Member::getBirthDate() const
{
    return birthDate;
}


void Member::printEntity() const
{
    Entity::printEntity();
    cout << "Birth Date: " << birthDate->getDateStr() << "\n";
}
