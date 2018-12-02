//
//  Status.hpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef Status_hpp
#define Status_hpp

#include "constants.hpp"
#include "Date.hpp"
#include "Time.hpp"
#include "Fanpage.hpp"


class Status
{
public:
    // Methods
    enum type {Text = 1, Image = 2, Video = 3};
    char* typeNames[3] = {"Text", "Image", "Video"};
    
    Status(type contentType, char* content)
    {
        this->date = new Date();
        this->time = new Time();
        this->contentType = contentType;
        strcpy(this->content, content);
    }
    const Date*   getDate()       const {return date;}
    const Time*   getTime()       const {return time;}
    const type    getType()       const {return contentType;}
    const char*   getContent()    const;
    void          printStatus()   const;
    
private:
    // Attributes
    Date*    date;
    Time*    time;
    type    contentType;
    char    content[STATUS_MAX_SIZE] = "";
};

#endif /* Status_hpp */










