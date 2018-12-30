#pragma once
//
//  Member.hpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright � 2018 Ilan Kushnir. All rights reserved.
//

#ifndef __Member_h
#define __Member_h

#include "Fanpage.h"
#include "Entity.h"
#include "Date.h"
#include "Time.h"
#include "Status.h"


class Member : public Entity
{
private:
    //attributes
    //    char        name[NAME_MAX_SIZE];
    Date*       birthDate;
    //    Status**    statuses = nullptr;
    //    int         statusesCount = 0;
    //    int         statusesArrSize = 0;
    //    Member**    friends = nullptr;
    int         friendsCount = 0;
    //    int         friendsArrSize = 0;
    //    Fanpage**   fanPages = nullptr;
    int         fanPagesCount = 0;
    //    int         fanPagesArrSize = 0;
    
    
public:
    // Constructor, Distructor
    Member(char* name, Date* birthDate) : Entity(name)
    {
        this->birthDate = birthDate;
    }
    
    ~Member()
    {
        delete birthDate;
    }
    
    // Methods
    Status**            getAllFriendsRecentStatuses()   const;
    Status**            fetchFriendsStatuses()   const;
    bool                addFriend(Member* newFriend);
    bool                addFanPage(Fanpage* newFanPage);
    Fanpage**           getFanPages()      const;
    Member**            getFriends()       const;
    int                 getFriendsCount();
    Date*               getBirthDate()     const;
    virtual void        printEntity()      const override;
};



#endif /* Member_h */
