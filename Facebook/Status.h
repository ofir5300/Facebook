#pragma once
//
//  Status.h
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef __Status_h
#define __Status_h

#include "constants.h"
#include "Date.h"
#include "Time.h"


class Status
{
public:
	// Methods
	enum type { Text = 1, Image = 2, Video = 3, Text_Image = 4, Text_Video = 5 };
	char* typeNames[5] = { "Text", "Image", "Video", "Text & Image", "Text & Video" };

	Status(type contentType, char* content)
	{
		this->date = new Date();
		this->time = new Time();
		this->contentType = contentType;
		strcpy(this->content, content);
	}
	const Date* getDate()       const { return date; }
	const Time* getTime()       const { return time; }
	const type  getType()       const { return contentType; }
	const char* getContent()    const;
	void        printStatus()   const;
	int			compare(Status* other);
	bool		operator==(const Status& other) const;
	bool		operator!=(const Status& other) const;

private:
	// Attributes
	Date*    date;
	Time*    time;
	type    contentType;
	char    content[STATUS_MAX_SIZE] = "";
};

#endif /* Status_h */











