//
//  Facebook.cpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright � 2018 Ilan Kushnir. All rights reserved.
//

#include "Facebook.h"

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
	cout << "9) Exit\n";
	cout << "\nExtra actions:\n";
	cout << "10) Display member's feed\n";
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
		displayAllMembersOfFanpageOrMember();
		break;
	case 9:
		exitFacebook();
		break;
	case 10:
		printRecentStatuses();
		break;
	default:
		cout << "Wrong input\n";
		break;
	}


}


void Facebook::displayStatuses()
{
	int choice = 0;
	char name[NAME_MAX_SIZE];

	while (choice != 1 && choice != 2)
	{
		cout << "Do you want to display the statuses of a memeber or a fanpage?\n"
			<< "1) Member\n"
			<< "2) Fanpage\n";
		cin >> choice;
	}

	if (choice == 1)
	{
		do
		{
			cout << "Please enter member name\n";
			cin.ignore();
			cin.getline(name, NAME_MAX_SIZE);
		} while (findMember(name) == nullptr);

		Member* member = findMember(name);
		Status** statuses = member->getStatuses();

		for (int i = 0; i < member->getStatusesCount(); i++)
		{
			statuses[i]->printStatus();
		}
	}
	else
	{
		do
		{
			cout << "Please enter fanpage name\n";
			cin.ignore();
			cin.getline(name, NAME_MAX_SIZE);
		} while (findFanpage(name) == nullptr);

		Fanpage* fanpage = findFanpage(name);
		Status** statuses = fanpage->getStatuses();

		for (int i = 0; i < fanpage->getStatusesCount(); i++)
		{
			statuses[i]->printStatus();
		}
	}
}

void Facebook::displayAllMembers()
{
	if (members == nullptr)
		cout << "There are no members subscriptions\n";

	for (int i = 0; i < membersCount; i++)
	{
		members[i]->printMember();
	}

}

void Facebook::displayAllMembersAndFanpages()
{
	displayAllMembers();

	if (fanpages == nullptr)
		cout << "\nThere are no fanpages subscriptions\n";

	for (int i = 0; i < fanpageCount; i++)
	{
		fanpages[i]->printFanpage();
	}
}

void Facebook::displayAllMembersOfFanpageOrMember()
{
	int choice = 0;
	char name[NAME_MAX_SIZE];

	while (choice != 1 && choice != 2)
	{
		cout << "Do you want to display fans of a fanpage or friends of a member?\n"
			<< "1) A Member's friends\n"
			<< "2) A Fanpage's fans\n";
		cin >> choice;
	}

	if (choice == 1)
	{
		do
		{
			cout << "Please enter member name\n";
			cin.ignore();
			cin.getline(name, NAME_MAX_SIZE);
		} while (findMember(name) == nullptr);

		Member* member = findMember(name);          // prints "member founds twice"
		Member** friends = member->getFriends();

		for (int i = 0; i < member->getFriendsCount(); i++)
		{
			friends[i]->printMember();
		}
	}
	else
	{
		do
		{
			cout << "Please enter fanpage name\n";
			cin.ignore();
			cin.getline(name, NAME_MAX_SIZE);
		} while (findFanpage(name) == nullptr);

		Fanpage* fanpage = findFanpage(name);
		Member** fans = fanpage->getFans();

		for (int i = 0; i < fanpage->getFansCount(); i++)
		{
			fans[i]->printMember();
		}
	}

}

bool Facebook::addMember()
{
	char name[NAME_MAX_SIZE];
	char date[11];

	cout << "Please enter the member's name:\n";
	cin.ignore();
	cin.getline(name, NAME_MAX_SIZE);
	cout << "Please enter the member's birthdate\n"
		<< "in the following format: dd/mm/yyyy\n";
	cin >> date;
	Date* birthdate = new Date(date);

	Member* newMember = new Member(name, birthdate);

	if (membersArrSize == 0) {
		members = new Member*[INITIAL_ARR_DYNAMIC_SIZE];
		membersArrSize = INITIAL_ARR_DYNAMIC_SIZE;
		membersCount = 0;
	}
	else if (membersCount == membersArrSize)
	{
		Member** temp = members;
		membersArrSize *= 2;
		members = new Member*[membersArrSize];
		memcpy(members, temp, sizeof(Member*) * membersCount);
		delete[]temp;
	}

	members[membersCount++] = newMember;
	return true;
}

bool Facebook::addFanpage()
{
	char name[NAME_MAX_SIZE];

	cout << "Please enter the fanpage's name:\n";
	cin.ignore();
	cin.getline(name, NAME_MAX_SIZE);

	Fanpage* newFanepage = new Fanpage(name);

	if (fanpageArrSize == 0) {
		fanpages = new Fanpage*[INITIAL_ARR_DYNAMIC_SIZE];
		fanpageArrSize = INITIAL_ARR_DYNAMIC_SIZE;
		fanpageCount = 0;
	}
	else if (fanpageCount == fanpageArrSize)
	{
		Fanpage** temp = fanpages;
		fanpageArrSize *= 2;
		fanpages = new Fanpage*[fanpageArrSize];
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
	Member* member = nullptr;
	Fanpage* fanpage = nullptr;

	while (choice != 1 && choice != 2) {
		cout << "Do you want to add the status to a memeber or to a fanpage?\n"
			<< "1) Member\n"
			<< "2) Fanpage\n";

		cin >> choice;
	}

	if (choice == 1) // member
	{
		cout << "Enter member's name:\n";
		cin.ignore();
		cin.getline(name, NAME_MAX_SIZE);
		member = findMember(name);

		if (member == nullptr)
			return false;
	}
	else if (choice == 2) // fanpage
	{
		cout << "Enter fanpage's name:\n";
		cin.ignore();
		cin.getline(name, NAME_MAX_SIZE);
		fanpage = findFanpage(name);

		if (fanpage == nullptr)
			return false;
	}

	cout << "Choose status type:\n"
		<< "1) Text\n"
		<< "2) Image\n"
		<< "3) Video\n";
	cin >> statusType;

	cout << "Enter status:\n";
	cin.ignore();                               // clean the buffer before pulling status text fro the console
	cin.getline(status, STATUS_MAX_SIZE);

	Status* newStatus = new Status((Status::type)statusType, status);

	if (choice == 1)
	{
		member->addStatus(newStatus);
		return true;
	}
	else if (choice == 2)
	{
		fanpage->addStatus(newStatus);
		return true;
	}

	return false;
}

Member* Facebook::findMember(char* name)
{
	for (int i = 0; i < membersCount; i++) {
		if (strcmp(name, members[i]->getName()) == 0) {
			//            cout << "--- Member found! ---\n";
			return members[i];
		}
	}

	cout << "--- Member not found ---\n";
	return nullptr;
}

Fanpage* Facebook::findFanpage(char* name)
{
	for (int i = 0; i < fanpageCount; i++) {
		if (strcmp(name, fanpages[i]->getName()) == 0) {
			//            cout << "--- Fanpage found! ---\n";
			return fanpages[i];
		}
	}

	cout << "Fanpage not found\n";
	return nullptr;
}

bool Facebook::pair2Members()
{
	Member* m1 = nullptr, *m2 = nullptr;
	char name1[NAME_MAX_SIZE], name2[NAME_MAX_SIZE];

	cout << "Please enter first member's name:\n";
	cin.ignore();
	cin.getline(name1, NAME_MAX_SIZE);

	m1 = findMember(name1);
	if (m1 == nullptr) { return false; }

	cout << "Please enter second member's name:\n";
	//    cin.ignore();
	cin.getline(name2, NAME_MAX_SIZE);

	m2 = findMember(name2);
	if (m2 == nullptr) { return false; }

	m1->addFriend(m2);
	m2->addFriend(m1);
	return true;
}

bool Facebook::pairFanToFanpage()
{
	Member* member = nullptr;
	Fanpage* fanpage = nullptr;
	char memberName[NAME_MAX_SIZE], fanpageName[NAME_MAX_SIZE];

	cout << "Please enter member's name:\n";
	cin.ignore();
	cin.getline(memberName, NAME_MAX_SIZE);

	member = findMember(memberName);
	if (member == nullptr) { return false; }

	cout << "Please enter fanpage's name:\n";
	//    cin.ignore();
	cin.getline(fanpageName, NAME_MAX_SIZE);

	fanpage = findFanpage(fanpageName);
	if (fanpage == nullptr) { return false; }

	member->addFanPage(fanpage);
	fanpage->addFan(member);
	return true;
}

void Facebook::exitFacebook()
{
	for (int i = 0; i < membersCount; i++)
		delete members[i];
	for (int i = 0; i < fanpageCount; i++)
		delete fanpages[i];

	delete members;
	delete fanpages;
}


void Facebook::printRecentStatuses()
{
	char name[NAME_MAX_SIZE];

	do
	{
		cout << "Please enter member name:\n";
		cin.ignore();
		cin.getline(name, NAME_MAX_SIZE);
	} while (findMember(name) == nullptr);

	Member* member = findMember(name);
	Status** recent = member->getAllFriendsRecentStatuses();

	for (int i = 0; i < RECENT_STATUSES; i++)
	{
		if (i == 0 && recent == nullptr)    // no statuses at all
		{
			cout << "There are no statuses yet\n";
			break;
		}
		else if (recent[i] != nullptr)
			recent[i]->printStatus();
		else    // no more statuses in feed
			break;
	}
}

