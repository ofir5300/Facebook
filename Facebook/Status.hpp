//
//  Status.hpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef Status_hpp
#define Status_hpp

#include "Date.hpp"
#include "Time.hpp"
#include "Fanpage.hpp"


class Status
{
private:
    // Attributes
    Date    date;
    Time    time;
    enum    type {Text, Image, Video};
    char    content[STATUS_MAX_SIZE] = "";
public:
    // Methods
    Status(enum type, char* content)
    {
        this.date = new Date();
        this.time = new Time();
        this.type = type;
        strcpy(this.content, content);
        
    }
    const Date&   getDate()       const;
    const Time&   getTime()       const;
    const enum    getType()       const;        /////// add swich -std=c++11 ? 
    const char*   getContent()    const;
};

#endif /* Status_hpp */










