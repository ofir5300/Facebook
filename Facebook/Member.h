#pragma once
//
//  Member.hpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef __Member_h
#define __Member_h

#include "Entity.h"
#include "Date.h"
#include "Time.h"
#include "Status.h"
//#include "Fanpage.h"

class Fanpage;

class Member : public Entity
{
private:
	//attributes
	Date*       birthDate;
	int         friendsCount = 0;
	int         fanPagesCount = 0;


public:
	// Constructor, Distructor
	Member(const string& name, Date* birthDate) : Entity(name)
	{
		this->birthDate = birthDate;
	}

	~Member()
	{
		delete birthDate;
	}

	// Methods
	Status**            getAllFriendsRecentStatuses()   const;
	Status**            fetchFriendsStatuses()			const;
	bool                addFriend(Member* newFriend);
	bool                addFanPage(Fanpage* newFanPage);
	Fanpage**           getFanPages()					const;
	Member**            getFriends()					const;
	int                 getFriendsCount();
	Date*               getBirthDate()					const;
	virtual void        printEntity()					const override;
	Member&				operator+=(Member& other);
};



#endif /* Member_h */
