#ifndef Courses_Placement_H
#define Courses_Placement_H
#include "UserInterface.h"
#include "seasonConfig.h"
#include <iostream>
class finalCourses : public UserInterface{
public:
	seasonConfig season;
	finalCourses(CourseBid* context, seasonConfig season1);
	void display();
	bool checkData(int input);
};


#endif