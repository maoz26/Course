#ifndef EnterSec_H
#define EnterSec_H
#include "UserInterface.h"
#include "seasonConfig.h"
#include <iostream>
using namespace std;

class EnterSec : public UserInterface{

public:
	seasonConfig season;

	EnterSec(CourseBid* context, seasonConfig season1);

	void display();

	bool checkData(int input);


};


#endif