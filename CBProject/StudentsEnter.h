#ifndef StudentsEnter_H
#define StudentsEnter_H
#include "seasonConfig.h"
#include "UserInterface.h"
#include <iostream>

using namespace std;

class studentsEnter : public UserInterface{

public:
	int wrongPassword = 0;
	seasonConfig season;
	
	

	studentsEnter(CourseBid* context, seasonConfig season1);
	bool checkData(int input);
	void display();
	void checkPassword();
	 
};

#endif 