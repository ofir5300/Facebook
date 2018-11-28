//
//  Facebook.hpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef Facebook_hpp
#define Facebook_hpp

#include "constants.hpp"
#include "Member.hpp"
#include "Fanpage.hpp"
#include "Status.hpp"

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
    void exitFacebook();
    
    Member*     findMember(char* name);
    Fanpage*    findFanpage(char* name);
};


#endif /* Facebook_hpp */
