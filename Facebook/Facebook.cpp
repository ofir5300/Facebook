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
//    switch (funcNum) {
//        case 1:
//            addMember();
//            break;
//        case 2:
//            addFanpage();
//            break;
//        case 3:
//            addStatus();
//            break;
//        case 4:
//            displayStatuses();
//            break;
//        case 5:
//            pair2Members();
//            break;
//        case 6:
//            pairFanToFanpage();
//            break;
//        case 7:
//            displayAllMembersAndFanpages();
//            break;
//        case 8:
//            displayAllMembers();
//            break;
//        case 9:
//            exitFacebook();
//            break;
//
//        default:
//            cout << "Wrong input\n";
//            break;
//    }
//    
}

bool Facebook::addMember()
{
    char name[NAME_MAX_SIZE];
    char date[11];
    
    cout << "Please enter the member's name:\n";
    cin >> name;
    cout << "Please enter the member's birthdate\n"
         << "in the following format: dd/mm/yyyy";
    cin >> date;
    Date* birthdate = new Date(date);
    
    Member* newMember = new Member(name, birthdate);
    
    if (membersArrSize == 0) {
        members = new Member* [INITIAL_ARR_DYNAMIC_SIZE];
        membersArrSize = INITIAL_ARR_DYNAMIC_SIZE;
        membersCount = 0;
    }
    else if (membersCount == membersArrSize)
    {
        Member** temp = members;
        membersArrSize *= 2;
        members = new Member* [membersArrSize];
        memcpy(members, temp, sizeof(Member*) * membersCount);
        delete []temp;
    }
    
    members[membersCount++] = newMember;
    return true;
}

bool Facebook::addFanpage()
{
    char name[NAME_MAX_SIZE];
    
    cout << "Please enter the fanpage's name:\n";
    cin >> name;
    
    Fanpage* newFanepage = new Fanpage(name);
    
    if (fanpageArrSize == 0) {
        fanpages = new Fanpage* [INITIAL_ARR_DYNAMIC_SIZE];
        fanpageArrSize = INITIAL_ARR_DYNAMIC_SIZE;
        fanpageCount = 0;
    }
    else if (fanpageCount == fanpageArrSize)
    {
        Fanpage** temp = fanpages;
        fanpageArrSize *= 2;
        fanpages = new Fanpage* [fanpageArrSize];
        memcpy(fanpages, temp, fanpageCount);
        delete temp;
    }
    
    fanpages[fanpageCount++] = newFanepage;
    return true;
}

bool Facebook::addStatus()
{
    int choice = 0; // 1 - member, 2 - fanpage
    int statusType; //
    char status[STATUS_MAX_SIZE];
    char name[NAME_MAX_SIZE];
    
    while (choice != 1 || choice != 2) {
        cout << "Do you want to add the status to a memeber or to a fanpage?\n"
        << "1) Member\n"
        << "2) Fanpage\n";
        
        cin >> choice;
    }
    
    if (choice == 1) // member
    {
        cout << "Enter member's name:\n";
        cin >> name;
        Member* member = findMember(name);
        
        if (member == nullptr)
            return false;
    }
    else if (choice == 2) // fanpage
    {
        cout << "Enter fanpage's name:\n";
        cin >> name;
        Fanpage* fanpage = findFanpage(name);
        
        if (fanpage == nullptr)
            return false;
    }
    
    cout << "Choose status type:\n"
         << "1) Text\n"
         << "2) Image\n"
         << "3) Video\n";
    cin >> statusType;
    
    cout << "Enter status:\n";
    cin >> status;
    
    Status* newStatus = new Status(statusType, status);
    ////////////////////////////////////////////////////
    
}




Member* Facebook::findMember(char* name)
{
    for (int i = 0; i < membersCount; i++) {
        if (strcmp(name, members[i]->getName()) == 0) {
            return members[i];
        }
    }
    
    cout << "Member not found";
    return nullptr;
}

Fanpage* Facebook::findFanpage(char* name)
{
    for (int i = 0; i < fanpageCount; i++) {
        if (strcmp(name, fanpages[i]->getName()) == 0) {
            return fanpages[i];
        }
    }
    
    cout << "Fanpage not found";
    return nullptr;
}
