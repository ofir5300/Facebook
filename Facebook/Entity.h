//
//  Entity.h
//  Facebook
//
//  Created by Ofir Cohen on 28/12/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include "constants.h"

#include "Status.h"

class Entity {
private:
    // Attributes
    char        name[NAME_MAX_SIZE];
    Status**    statuses = nullptr;
    int         statusesCount = 0;
    int         statusesArrSize = 0;
    Entity**    connections = nullptr;
    int         connectionsCount = 0;
    int         connectionsArrSize = 0;

public:
    Entity(char* name)
    {
        strcpy(this->name, name);
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
    
    char*       getName();
    Entity**    getConnections()                   const;
    int         getConnectionsCount();
    bool        addStatus(Status* newStatus);
    Status**    getStatuses()               const;
    int         getStatusesCount()          const;
    void        printEntity()               const;
    Status**    getRecentStatuses()         const;
    Status*     getMostRecentStatus();
    bool        addConnection(Entity* newConnection);






};



#endif /* Entity_h */
