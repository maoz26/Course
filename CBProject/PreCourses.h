#ifndef PreCourses_H
#define PreCourses_H
#include "UserInterface.h"
#include "seasonConfig.h"
#include "Course.h"
#include "Student.h"
class PreCourses : public UserInterface{
public:
	seasonConfig season;
	int idobj;
	int cur_sel;
	PreCourses(CourseBid* context1, seasonConfig season1, int idobj1);

	bool checkData(int input);

	void display();

	void add(int index, int idobj);

	void remove(int index, int idobj);
	void returnStateCourseEntry();

};

#endif