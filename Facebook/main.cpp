//
//  main.cpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#include "Facebook.hpp"

int main(int argc, const char * argv[]) {
    
    int input = 0;
    Facebook fb;

    cout << "Welcome to Facebook! \n";
    fb.displayMenu();
    
//    Date dt(13,04,1993);
//    Member abit("abit", &dt);
//    Date dt1(19,05,1993);
//    Member melech("melech", &dt1);
//    Date dt2(11,11,1999);
//    Member aba("aba", &dt2);

    do {
        cout << "\nPlease choose action:\n";
        cin.clear();
        cin >> input;
        fb.runFunction(input);
    } while (input != 9);
    
    return 0;
}
