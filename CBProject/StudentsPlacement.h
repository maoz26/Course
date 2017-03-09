#ifndef Students_Placement_H
#define Students_Placement_H
#include "UserInterface.h"
#include "seasonConfig.h"
class finalStudents : public UserInterface{
public:
	seasonConfig season;
	finalStudents(CourseBid* context, seasonConfig season1);
	void display();
	bool checkData(int input);
};


#endif