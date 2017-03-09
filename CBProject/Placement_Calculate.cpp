#include "Placement_Calculate.h"
#include "CourseListEdit.h"
#include "StudentsListEdit.h"
#include "EnterSec.h"
#include "StudentsPlacement.h"
#include "CoursesPlacement.h"
#include <iostream>
using namespace std;

Placement::Placement(CourseBid* context, seasonConfig season1) : season(season1){
	this->context = context;
}

void Placement::display()
{

	cout << "Press 1 to Studnet final courses \n";
	cout << "Press 2 to Course final students \n";
	cout << "Press b to back \n";
	cout << "Press q to quit \n";
}


bool Placement::checkData(int input){
	switch (input)
	{
	case '1':
	{
		finalStudents* state1 = new finalStudents(context, season);
		context->setState(state1);
		break;
	}
	case '2':
	{
		finalCourses* state2 = new finalCourses(context, season);
		context->setState(state2);
		break;
	}
	case 'b':
	{
		EnterSec* state3 = new EnterSec(context, season);
		context->setState(state3);
		break;
	}
	case 'q':
	case 'Q':
		return false;
	default:
		break;

	};
	return true;
};
