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
    
    do {
        cin >> input;
        fb.runFunction(input);
    } while (input != 9);
    
    return 0;
}
