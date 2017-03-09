#ifndef StudentsFinalCourse_H
#define StudentsFinalCourse_H
#include "UserInterface.h"
#include "Student.h"
class StudentsFinalCourse : public UserInterface{
public:
	Student student;
	StudentsFinalCourse(CourseBid*context, Student student);
	void display();
	bool checkData(int input);


};








#endif