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
//#include "Fanpage.hpp"

class Date;

class Fanpage;

class Status
{
private:
    // Attributes
    Date    date;
    Time    time;
    type    contentType;
    char    content[STATUS_MAX_SIZE] = "";
public:
    // Methods
    Status(type contentType, char* content)
    {
        this->date = Date();
        this->time = Time();
        this->contentType = contentType;
        strcpy(this->content, content);
    }
    const Date&   getDate()       const;
    const Time&   getTime()       const;
    const type    getType()       const;        /////// add swich -std=c++11 ?
    const char*   getContent()    const;
    void          printStatus()   const;
};

#endif /* Status_hpp */










