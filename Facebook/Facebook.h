//
//  Facebook.hpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright � 2018 Ilan Kushnir. All rights reserved.
//

#ifndef __Facebook_h
#define __Facebook_h

#include "constants.h"
#include "Entity.h"
#include "Member.h"
///////////////
#include "Fanpage.h"

class Facebook
{
private:
    // Attributes
    Member**    members = nullptr;
    int         membersCount = 0;
    int         membersArrSize = 0;
    Fanpage**   fanpages = nullptr;
    int         fanpageCount = 0;
    int         fanpageArrSize = 0;
    
public:
    // Methods
    void displayMenu();
    void runFunction(int funcNum);
    
    bool addMember();
    bool addFanpage();
    bool addStatus();
    void displayStatuses();
    bool pair2Members();
    bool pairFanToFanpage();
    void displayAllMembersAndFanpages();
    void displayAllMembers();
    void displayAllMembersOfFanpageOrMember();
    void exitFacebook();
    
    Member*     findMember(char* name);
    Fanpage*    findFanpage(char* name);
    void printRecentStatuses();
};
















#endif /* Facebook_h */
