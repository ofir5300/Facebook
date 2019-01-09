//
//  Entity.h
//  Facebook
//
//  Created by Ofir Cohen on 28/12/2018.
//  Copyright � 2018 Ilan Kushnir. All rights reserved.
//

#ifndef __Entity_h
#define __Entity_h

#include "constants.h"
#include "Status.h"
////////////////////


class Entity {
protected:
	// Attributes
	//char        name[NAME_MAX_SIZE];
	string		name;
	Status**    statuses = nullptr;
	int         statusesCount = 0;
	int         statusesArrSize = 0;
	Entity**    connections = nullptr;
	int         connectionsCount = 0;
	int         connectionsArrSize = 0;

public:
	Entity(const string& name)
	{
		this->name = name;
	}
	~Entity()
	{
		if (connectionsCount != 0) {
			delete[]connections;
		}
		if (statusesCount != 0) {
			for (int i = 0; i < statusesCount; i++) {
				delete statuses[i];
			}
			delete[]statuses;
		}
	}

	string      getName();
	Entity**    getConnections()                   const;
	int         getConnectionsCount() const;
	bool        addStatus(Status* newStatus);
	Status**    getStatuses()               const;
	int         getStatusesCount()          const;
	virtual void        printEntity() const;
	Status**    getRecentStatuses()         const;
	Status*     getMostRecentStatus();
	bool        addConnection(Entity* newConnection);
	bool        operator>(const Entity& other) const;



};



#endif /* Entity_h */
