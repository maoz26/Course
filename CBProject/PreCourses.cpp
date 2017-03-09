#include "PreCourses.h"
#include "EditCourse.h"
#include <string>
#include <exception>
#include <iostream>
using namespace std;

PreCourses::PreCourses(CourseBid* context1, seasonConfig season1, int idobj1) : season(season1), idobj(idobj1), cur_sel(0){
	context = context1;
}

bool PreCourses::checkData(int input){
	try{
		switch (input)
		{
		case '1':
			add(cur_sel, idobj);
			break;
		case '2':
			remove(cur_sel, idobj);
			break;
		case 'b':
			returnStateCourseEntry();
			break;
		
		case 'q':
		case 'Q':
			return false;
		default:
			break;

		};
	}
	catch (exception &e){
		cout << e.what() << "\n";
	}


	return true;
};

void PreCourses::display(){
	int x = season.courseList.count() - 1;
	if (season.courseList.count() - 1 == 0)
	{
		cout << "No courses \n";
	}
	else
		for (int i = 0; i < season.courseList.count() - 1; i++)
				cout << i << " :  " << season.courseList.get(i).get_id() << "\n";
		
	cout << "Opitions:  \n";
	cout << "Press 1 to add \n";
	cout << "Press 2 to remove \n";
	cout << "Press b to back \n";
	cout << "Press q to quit \n";
}

void PreCourses::add(int index, int idobj){
	if (season.courseList.count() - 1 == 0)
		throw exception("No courses to add");
	Course temp = season.courseList.get(index);
	Course course = season.getFactory().construct<Course>(idobj);
	for (int i = 0; i < season.courseList.get(i).pre.count(); i++)
		if (temp.id.get() == season.courseList.get(i).pre.get(i).id.get())
			cout << "Already in the list  \n";
		else
			course.pre.add(temp);
		cout << "Added successfully \n";	
}
void PreCourses::remove(int index, int idobj){

	if (season.courseList.count() == 0)
		throw exception("The list is empty");
	int idcourse = season.courseList.get(index).id.get();
	Course course = season.getFactory().construct<Course>(idobj);

	for (int i = 0; i < course.pre.count(); i++)
	{
		if (course.pre.get(i).id.get() == idcourse)
			course.pre.remove(i);

	}

	for (int i = 0; i < course.pre.count(); i++)
	{
		cout << course.pre.get(i).id.get() << ",";

	}
	cout << "Deleted successfully \n";

}

void PreCourses::returnStateCourseEntry(){
	EditCourse* state = new EditCourse(context, season, season.getFactory().construct<Course>(idobj));
	context->setState(state);
}