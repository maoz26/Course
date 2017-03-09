
#include "CompletedState.h"
#include "Course.h"
#include "Student.h"
#include "StudentSEdit.h"
#include <string>
#include <iostream>
using namespace std;

CombState::CombState(CourseBid* context1, seasonConfig season1, int idobj1) : season(season1), idobj(idobj1), cur_sel(0){
	context = context1;
}

bool CombState::checkData(int input){
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
			returnStudentEnrty();
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

void CombState::display(){

	for (int i = 0; i < season.courseList.count(); i++)
			cout << i << " :  " << season.courseList.get(i).id.get() << "\n";
	cout << "\n Opitions:  \n";
	cout << "Press 1 to add \n";
	cout << "Press 2 to delete \n";
	cout << "Press b to back \n";
	cout << "Press q to quit \n";
}

void CombState::add(int index, int idobj){
	if (season.courseList.count() == 0)
		throw exception("No courses to add");
	Course temp = season.courseList.get(index);
	Student student = season.getFactory().construct<Student>(idobj);
	for (int i = 0; i < season.studentList.get(i).completed.count(); i++)
		if (temp.id.get() == season.studentList.get(i).completed.get(i).id.get())
			cout << "Already in the list  \n";
		else
			student.completed.add(temp);
	cout << "Added successfully \n";

}
void CombState::remove(int index, int idobj){
	int idcourse = season.courseList.get(index).id.get();
	Student student = season.getFactory().construct<Student>(idobj);
	for (int i = 0; i < student.completed.count(); i++)
	{
		if (student.completed.get(i).id.get() == idcourse)
			student.completed.remove(i);

	}

	for (int i = 0; i < student.completed.count(); i++)
	{
		cout << student.completed.get(i).id.get() << ",";

	}
	cout << "Deleted successfully \n";

}

void CombState::returnStudentEnrty(){
	StudentsEdit* state = new StudentsEdit(context, season, season.getFactory().construct<Student>(idobj));
	context->setState(state);
}