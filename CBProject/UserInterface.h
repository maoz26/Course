#pragma once
#ifndef UserInterface_H
#define UserInterface_H
#include "CourseBid.h"
class UserInterface{

public:

	CourseBid* context;

	virtual bool checkData(int input) = 0;

	virtual void display() = 0;

};


#endif