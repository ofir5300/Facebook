//
//  Status.hpp
//  Facebook
//
//  Created by Ofir Cohen on 25/11/2018.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#ifndef Status_hpp
#define Status_hpp

#include <stdio.h>
#include "Date.hpp"
#include "Time.hpp"
#include "Fanpage.hpp"

class Status
{
private:
    //attributes
    Date    date;
    Time    time;
    enum    type;
    char    content[STATUS_MAX_SIZE] = "";
public:
    //methods
    Date&   getDate()       const;
    Time&   getTime()       const;
    enum    getType()       const;
    char*   getContent()    const;
};

#endif /* Status_hpp */
