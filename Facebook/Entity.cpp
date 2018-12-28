//
//  Entity.cpp
//  Facebook
//
//  Created by Ofir Cohen on 28/12/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#include "Entity.h"

Status** Entity::getStatuses() const
{
    return statuses;
}

int Entity::getStatusesCount() const
{
    return statusesCount;
}

int Entity::getConnectionsCount()
{
    return connectionsCount;
}

Status** Entity::getRecentStatuses() const
{   // retruns an array of 10 last statuses, or all statuses if less than 10
    Status** recent = new Status*[(RECENT_STATUSES > statusesCount) ? RECENT_STATUSES : statusesCount];
    for (int i = 0; i < RECENT_STATUSES && i < statusesCount; i++)
    {
        recent[i] = statuses[i];
    }
    
    return recent;
}

Status* Entity::getMostRecentStatus()
{
    return (statuses == nullptr) ? nullptr : statuses[statusesCount - 1];
}

bool Entity::addConnection(Entity* newConnection)
{   // add a new connection to 'connections' array
    
    if (!connectionsCount)   // if array is empty
    {
        connectionsArrSize = INITIAL_ARR_DYNAMIC_SIZE;
        connections = new Entity*[connectionsArrSize];
    }
    else if (connectionsCount == connectionsArrSize && connectionsCount != 0)
    {
        Entity** temp = connections;
        connectionsArrSize *= 2;
        connections = new Entity*[connectionsArrSize];
        memcpy(connections, temp, sizeof(Entity*) * connectionsCount);
    }
    
    connections[connectionsCount++] = newConnection;
    return true;
}

char* Entity::getName()
{
    return name;
}

Entity** Entity::getConnections() const
{
    return connections;
}

void Entity::printEntity() const
{
    cout << "\n" << (typeid(*this).name() + 6) << "'s name: " << name << "\n";
}

bool Entity::addStatus(Status* newStatus)
{
    if (statuses == nullptr) {
        statuses = new Status*[INITIAL_ARR_DYNAMIC_SIZE];
        statusesArrSize = INITIAL_ARR_DYNAMIC_SIZE;
        statusesCount = 0;
    }
    else if (statusesCount == statusesArrSize)
    {
        Status** temp = statuses;
        statusesArrSize *= 2;
        statuses = new Status*[statusesArrSize];
        memcpy(statuses, temp, sizeof(Status*) * statusesCount);
        delete temp;
    }
    
    statuses[statusesCount++] = newStatus;
    return true;
}

