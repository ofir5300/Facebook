//
//  Facebook.hpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef Facebook_hpp
#define Facebook_hpp

#include <iostream>
#include "constants.hpp"
#include "Member.hpp"
#include "Fanpage.hpp"
#include "Status.hpp"

using namespace std;

class Facebook
{
private:
    Member**    members = nullptr;
    int         membersCount = 0;
    int         membersArrSize = 0;
    Fanpage**   fanpages = nullptr;
    int         fanpageCount = 0;
    int         fanpageArrSize = 0;
    
public:
    void displayMenu();
    bool addMember();
    bool addFanpage();
    bool addStatus();
    void displayStatuses();
    bool pair2Members();
    bool pairFanToFanpage();
    void displayAllMembersAndFanpages();
    void displayAllMembers();
    void exit();
};


#endif /* Facebook_hpp */
