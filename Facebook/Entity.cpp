#include "Entity.h"



vector<Status*> Entity::getStatuses() const
{
	return statuses;
}

int Entity::getStatusesCount() const
{
	return statuses.size();
}

int Entity::getConnectionsCount() const
{
	return connections.size();
}

Status* Entity::getMostRecentStatus()
{
	return (!statuses.empty()) ? nullptr : statuses.back();
}

bool Entity::addConnection(Entity* newConnection)
{   
	// add a new connection to 'connections' array
	connections.push_back(newConnection);
	return true;
}

string Entity::getName()
{
	return name;
}

vector<Entity*> Entity::getConnections() const
{
	return connections;
}

void Entity::printEntity() const
{
	cout << "\n" << (typeid(*this).name() + 6) << "'s name: " << name << "\n";
}

bool Entity::addStatus(Status* newStatus)
{
	statuses.push_back(newStatus);
	return true;
}

bool Entity::operator>(const Entity& other) const
{
	return (connections.size() >= other.getConnectionsCount());
}







