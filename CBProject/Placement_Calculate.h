#ifndef Placement_Calculate_H
#define Placement_Calculate_H
#include "UserInterface.h"
#include "seasonConfig.h"
#include <iostream>
using namespace std;


class Placement : public UserInterface{

public:
	seasonConfig season;

	Placement(CourseBid* context, seasonConfig season);

	void display();

	bool checkData(int input);

};


#endif 