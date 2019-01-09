//
//  Facebook.hpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef __Facebook_h
#define __Facebook_h

#include "constants.h"
#include "Date.h"
#include "Time.h"
#include "Status.h"
#include "Entity.h"
#include "Member.h"
#include "Fanpage.h"


class Facebook
{
private:
	// Attributes
	Entity**    connections = nullptr;
	int         connectionsCount = 0;
	int         connectionsArrSize = 0;

	int         membersCount = 0;
	int         fanpageCount = 0;

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

	Member*     findMember(const string& name);
	Fanpage*    findFanpage(const string& name);
	void		printRecentStatuses();

};
















#endif /* Facebook_h */
