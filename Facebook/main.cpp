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
    
    Date dt = Date();
    dt.printDate();
    Time tm = Time(10,15,30);
    tm.printTime();

    cout << "Welcome to Facebook! \n";
    fb.displayMenu();

    do {
        cin.clear();
        cin >> input;
        fb.runFunction(input);
    } while (input != 9);
    
    return 0;
}
