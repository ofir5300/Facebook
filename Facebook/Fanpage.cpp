//
//  Fanpage.cpp
//  Facebook
//
//  Created by Ilan Kushnir on 25/11/18.
//  Copyright © 2018 Ilan Kushnir. All rights reserved.
//

#include "Fanpage.h"

bool Fanpage::addFan(Member* fan)
{
	addConnection((Entity*)fan);
	fansCount++;
	return true;
}

Fanpage& Fanpage:: operator+=(Member& other)
{
	this->addFan(&other);
	other.addFanPage(this);

	return *this;
}