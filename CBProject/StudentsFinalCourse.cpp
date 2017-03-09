#include "StudentsFinalCourse.h"
#include <iostream>
#include <string>
using namespace std;
StudentsFinalCourse::StudentsFinalCourse(CourseBid* context, Student student1) : student(student1){
	this->context = context;
}

void StudentsFinalCourse::display(){
	for (int i = 0; i < student.FinalCourses.count(); i++)
	{
		string name = student.FinalCourses.get(i).name.get();
		string id = to_string(student.FinalCourses.get(i).id.get());
		cout << i << " :  " << id << "," << name << "\n";

	}
	cout << "Press q for quit  \n";
	cout << "Press b for back \n";
}



bool StudentsFinalCourse::checkData(int input){
	switch (input)
	{
	case 'q':
	case 'Q':
		return false;
	default:
		break;
	};
	return true;
};
