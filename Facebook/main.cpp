//
//  main.cpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#include "Facebook.h"

int main(int argc, const char * argv[]) {
	int input = -1;
	Facebook fb;

	cout << "Welcome to Facebook! \n";
	fb.displayMenu();


	do {
		cout << "\nPlease choose action:\n";
		cin.clear();
		if (input != -1 && (input > 10 || input < 1))     // clear buffer if invalid variable inserted to input
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cin >> input;
		fb.runFunction(input);

	} while (input != 9);


	return 0;
}
