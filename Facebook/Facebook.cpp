//
//  Facebook.cpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#include "Facebook.hpp"

void Facebook::displayMenu()
{
    cout << "Choose action:\n";
    cout << "1) Add new friend\n";
    cout << "2) Add new fanpage\n";
    cout << "3) Add a status to member or fanpage\n";
    cout << "4) Show all member's or fanpage's statuses\n";
    cout << "5) Make two members friends\n";
    cout << "6) Add a fan to fanpage\n";
    cout << "7) Display all members and fanpages\n";
    cout << "8) Display all member's friends or fanpage's fans\n";
    cout << "9) Exit";
}


void Facebook::runFunction(int funcNum)
{
    switch (funcNum) {
        case 1:
            addMember();
            break;
        case 2:
            addFanpage();
            break;
        case 3:
            addStatus();
            break;
        case 4:
            displayStatuses();
            break;
        case 5:
            pair2Members();
            break;
        case 6:
            pairFanToFanpage();
            break;
        case 7:
            displayAllMembersAndFanpages();
            break;
        case 8:
            displayAllMembers();
            break;
        case 9:
            exitFacebook();
            break;

        default:
            cout << "Wrong input\n";
            break;
    }
}
