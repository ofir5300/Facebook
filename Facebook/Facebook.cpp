//
//  Facebook.cpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
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
	string name;
	//char name[NAME_MAX_SIZE];

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
			//cin.ignore();			??
			//cin.getline(name, NAME_MAX_SIZE);
			cin >> name;
		} while (findMember(name) == nullptr);

		Member* member = findMember(name);
		vector<Status*> statuses = member->getStatuses();

		vector<Status*>::iterator itr = statuses.begin();
		vector<Status*>::iterator itrEnd = statuses.end();

		for (; itr != itrEnd; ++itr)
			(*itr)->printStatus();

	}
	else
	{
		do
		{
			cout << "Please enter fanpage name\n";
			//cin.ignore();			??
			//cin.getline(name, NAME_MAX_SIZE);
			cin >> name;
		} while (findFanpage(name) == nullptr);

		Fanpage* fanpage = findFanpage(name);
		vector<Status*> statuses = fanpage->getStatuses();

		vector<Status*>::iterator itr = statuses.begin();
		vector<Status*>::iterator itrEnd = statuses.end();

		for (; itr != itrEnd; ++itr)
			(*itr)->printStatus();
	}
}

void Facebook::displayAllMembers()
{
	if (connections.empty() || !membersCount)
		cout << "There are no members subscriptions\n";
	else
	{
		vector<Entity*>::iterator itr = connections.begin();
		vector<Entity*>::iterator itrEnd = connections.end();

		for (; itr != itrEnd; ++itr) {
			if (typeid(*(*itr)) == typeid(Member))
				(*itr)->printEntity();
		}
	}

}

void Facebook::displayAllMembersAndFanpages()
{
	displayAllMembers();

	if (connections.empty() || !fanpageCount)
		cout << "\nThere are no fanpages subscriptions\n";
	else
	{
		vector<Entity*>::iterator itr = connections.begin();
		vector<Entity*>::iterator itrEnd = connections.end();

		for (; itr != itrEnd; ++itr) {
			if (typeid(*(*itr)) == typeid(Fanpage))
				(*itr)->printEntity();
		}
	}
}

void Facebook::displayAllMembersOfFanpageOrMember()
{
	int choice = 0;
	string name;
	//char name[NAME_MAX_SIZE];

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
			//cin.ignore();			??
			//cin.getline(name, NAME_MAX_SIZE);
			cin >> name;
		} while (findMember(name) == nullptr);

		Member* member = findMember(name);          // prints "member founds twice"
		vector<Entity*> connections = member->getConnections();

		vector<Entity*>::iterator itr = connections.begin();
		vector<Entity*>::iterator itrEnd = connections.end();

		for (; itr != itrEnd; ++itr) {
			if (typeid(*(*itr)) == typeid(Member))
				(*itr)->printEntity();
		}
	}
	else
	{
		do
		{
			cout << "Please enter fanpage name\n";
			//cin.ignore();			??
			//cin.getline(name, NAME_MAX_SIZE);
			cin >> name;
		} while (findFanpage(name) == nullptr);

		Fanpage* fanpage = findFanpage(name);
		vector<Entity*> connections = fanpage->getConnections();

		vector<Entity*>::iterator itr = connections.begin();
		vector<Entity*>::iterator itrEnd = connections.end();

		for (; itr != itrEnd; ++itr) {
			if (typeid(*(*itr)) == typeid(Member))
				(*itr)->printEntity();
		}
	}

}

bool Facebook::addMember()
{
	//char name[NAME_MAX_SIZE];
	string name;
	string date;

	cout << "Please enter the member's name:\n";
	//cin.ignore();			??
	//cin.getline(name, NAME_MAX_SIZE);
	cin >> name;
	cout << "Please enter the member's birthdate\n"
		<< "in the following format: dd/mm/yyyy\n";
	cin >> date;
	Date* birthdate = new Date(date);

	Member* newMember = new Member(name, birthdate);

	connections.push_back(newMember);
	membersCount++;
	return true;
}

bool Facebook::addFanpage()
{
	//char name[NAME_MAX_SIZE];
	string name;

	cout << "Please enter the fanpage's name:\n";
	//cin.ignore();			??
	//cin.getline(name, NAME_MAX_SIZE);
	cin >> name;

	Fanpage* newFanepage = new Fanpage(name);

	connections.push_back(newFanepage);
	fanpageCount++;
	return true;
}

bool Facebook::addStatus()
{
	int choice = 0; // 1 - member, 2 - fanpage
	int statusType; // 1 - text, 2 - image, 3 - video, 4 - text & image, 5 - text & video
					//char status[STATUS_MAX_SIZE];
					//char name[NAME_MAX_SIZE];
	string status, name;
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
		//cin.ignore();			??
		//cin.getline(name, NAME_MAX_SIZE);
		cin >> name;
		member = findMember(name);

		if (member == nullptr)
			return false;
	}
	else if (choice == 2) // fanpage
	{
		cout << "Enter fanpage's name:\n";
		//cin.ignore();			??
		//cin.getline(name, NAME_MAX_SIZE);
		cin >> name;
		fanpage = findFanpage(name);

		if (fanpage == nullptr)
			return false;
	}

	cout << "Choose status type:\n"
		<< "1) Text\n"
		<< "2) Image\n"
		<< "3) Video\n"
		<< "4) Text & Image\n"
		<< "5) Text & Video\n";
	cin >> statusType;

	cout << "Enter status:\n";
	//cin.ignore();                               // clean the buffer before pulling status text from the console
	//cin.getline(status, STATUS_MAX_SIZE);
	cin.clear();
	cin >> status;

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

Member* Facebook::findMember(const string& name)
{

	vector<Entity*>::iterator itr = connections.begin();
	vector<Entity*>::iterator itrEnd = connections.end();

	for (; itr != itrEnd; ++itr)
		if (typeid(*(*itr)) == typeid(Member) && name == (*itr)->getName())
			return (Member*)(*itr);

	cout << "--- Member not found ---\n";
	return nullptr;
}

Fanpage* Facebook::findFanpage(const string& name)
{
	vector<Entity*>::iterator itr = connections.begin();
	vector<Entity*>::iterator itrEnd = connections.end();

	for (; itr != itrEnd; ++itr)
		if (typeid(*(*itr)) == typeid(Fanpage) && name == (*itr)->getName())
			return (Fanpage*)(*itr);

	cout << "Fanpage not found\n";
	return nullptr;
}

bool Facebook::pair2Members()
{
	Member* m1 = nullptr, *m2 = nullptr;
	//char name1[NAME_MAX_SIZE], name2[NAME_MAX_SIZE];
	string name1, name2;

	cout << "Please enter first member's name:\n";
	//cin.ignore();			??
	//cin.getline(name, NAME_MAX_SIZE);
	cin >> name1;

	m1 = findMember(name1);
	if (m1 == nullptr) { return false; }

	cout << "Please enter second member's name:\n";
	//cin.ignore();			??
	//cin.getline(name, NAME_MAX_SIZE);
	cin >> name2;

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
	//char memberName[NAME_MAX_SIZE], fanpageName[NAME_MAX_SIZE];
	string memberName, fanpageName;

	cout << "Please enter member's name:\n";
	//cin.ignore();
	//cin.getline(memberName, NAME_MAX_SIZE);
	cin >> memberName;

	member = findMember(memberName);
	if (member == nullptr) { return false; }

	cout << "Please enter fanpage's name:\n";
	//    cin.ignore();
	//cin.getline(fanpageName, NAME_MAX_SIZE);
	cin >> fanpageName;

	fanpage = findFanpage(fanpageName);
	if (fanpage == nullptr) { return false; }

	member->addFanPage(fanpage);
	fanpage->addFan(member);
	return true;
}

void Facebook::exitFacebook()
{
	vector<Entity*>::iterator itr = connections.begin();
	vector<Entity*>::iterator itrEnd = connections.end();

	for (; itr != itrEnd; ++itr) {
		delete *itr;
	}
}


void Facebook::printRecentStatuses()
{
	//char name[NAME_MAX_SIZE];
	string name;

	do
	{
		cout << "Please enter member name:\n";
		//cin.ignore();			??
		//cin.getline(name, NAME_MAX_SIZE);
		cin >> name;
	} while (findMember(name) == nullptr);

	Member* member = findMember(name);
	vector<Status*> recent = member->getAllFriendsRecentStatuses();

	vector<Status*>::iterator itr = recent.begin();
	vector<Status*>::iterator itrEnd = recent.end();

	for (int i = 0; itr != itrEnd && i < RECENT_STATUSES; ++itr) {

		if (i == 0 && recent.empty()) {
			cout << "There are no statuses yet\n";
			break;
		}

		(*itr)->printStatus();
		i++;
	}
}
