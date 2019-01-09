//
//  Status.cpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#include "Status.h"

const char* Status::getContent() const
{
	return content;
}

void Status::printStatus() const
{
	cout << "Status posted on ";
	date->printDate();
	cout << " ";
	time->printTime();
	cout << "\n[" << typeNames[(int)contentType - 1] << "] : " << content << "\n";
}

int Status::compare(Status* other)
{
	int resultByDate = this->date->compare(other->date);
	int resultByTime = this->time->compare(other->time);

	if (resultByDate == 0)
		return resultByTime;
	return resultByDate;
}

bool Status::operator==(const Status & other) const
{
	return (strcmp(this->content, other.getContent()) == 0) && (this->contentType == other.getType());
}

bool Status::operator!=(const Status & other) const
{
	return !(operator==(other));
}

