#include "EditCourse.h"
#include <string>
#include <iostream>
using namespace std;
#include <conio.h>
#include <cstdlib>
#include <exception>
#include "EnterSec.h"
#include "CourseListEdit.h"
CourseListEdit::CourseListEdit(CourseBid* context, seasonConfig season1) : season(season1) {
	this->context = context;
}

string CourseListEdit::get(int index)
{
	if (season.courseList.count() == 0)
		throw exception("The list is empty");
	string id = to_string(season.courseList.get(index).id.get());
	string name = season.courseList.get(index).name.get();
	string value = id + "," + name;
	return value;
};

void  CourseListEdit::select(int index) {
	

	if (season.courseList.count() == 0)
		throw exception("The list is empty");
	cout << "Enter which course you want to edit: " << endl;
	cin >> index;
	EditCourse* state = new EditCourse(context, season, season.courseList.get(index));
	context->setState(state);
};


void CourseListEdit::myDelete(int index) {
	int input, idobj, flag = 0;
	if (season.courseList.count() == 0)
		throw exception("The list is empty");
	idobj = season.courseList.get(index).get_id();
	
	for (int i = 0; i < season.studentList.count(); i++)
	{
		for (int j = 0; j < season.studentList.get(i).completed.count(); j++){
			if (idobj == season.studentList.get(i).completed.get(j).get_id())
			{
				throw exception("This course couldn't be deleted beacuse it is in the completed list of student");
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0)
	{
		for (int i = 0; i < season.courseList.count(); i++){
			for (int j = 0; j < season.courseList.get(i).pre.count(); j++){
				if (idobj == season.courseList.get(i).pre.get(j).get_id())
				{
					throw exception("This course couldn't be deleted beacuse it appears in the pre course of course");
					flag = 1;
					break;
				}
			}
		}
	}

	if (flag == 1)
		throw exception("Not delete course");
	cout << "Are you sure you want to delete ? \n";
	cout << "if yes press '1' else press '0' \n";
	input = _getch();
	if (input)
		season.courseList.remove(index);
	else
		cout << "Not deleted \n";

};


void CourseListEdit::add(int index) {
	cout << "Please insert the following deatils \n";
	Course newCourse = season.courseList.allocateAndAdd();
	season.courseList.add(newCourse);
	EditCourse* state = new EditCourse(context, season, newCourse);
	for (int i = 0; i < state->getFieldCount();i++)
		state->edit(i);
	context->setState(state);

};

int CourseListEdit::countList() {
	return season.courseList.count();
}

void CourseListEdit::returnState(){
	system("CLS");
	EnterSec* state = new EnterSec(context, season);
	context->setState(state);

}



