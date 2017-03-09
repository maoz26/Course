
#include "StudentsListEdit.h"
#include "StudentsEdit.h"
#include "CourseListEdit.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include <conio.h>
#include <cstdlib>
#include "EnterSec.h"


StudentsListEdit::StudentsListEdit(CourseBid* context, seasonConfig season1) : season(season1) {
	this->context = context;
}

string StudentsListEdit::get(int index)
{

	return season.studentList.get(index).id.get() + "," + season.studentList.get(index).name.get();
};

void StudentsListEdit::select(int index) {
	cout << "Enter the index of the student that you want to edit: \n";
	cin >> index;
	StudentsEdit* state = new StudentsEdit(context, season, season.studentList.get(index));
	context->setState(state);
};

void StudentsListEdit::myDelete(int index) {
	int input;
	cout << "Are you sure you want to delete ? \n";
	cout << "if yes enter '1' otherwise enter '0' \n";
	cin >> input;
	if (input)
		season.studentList.remove(index);
	else
		cout << "Not deleted \n";
};

void StudentsListEdit::add(int index) {
	string input, val;
	cout << "Please insert the following deatils \n";
	Student newStudnet = season.studentList.allocateAndAdd();
	season.studentList.add(newStudnet);
	StudentsEdit* state = new StudentsEdit(context, season, newStudnet);
	for (int i = 0; i < state->getFieldCount(); i++)
		state->edit(i);
	context->setState(state);

};

int StudentsListEdit::countList() {
	return season.studentList.count();

}

void StudentsListEdit::returnState(){
	EnterSec* state = new EnterSec(context, season);
	context->setState(state);

}
