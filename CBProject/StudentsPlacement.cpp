#include "StudentsPlacement.h"

finalStudents::finalStudents(CourseBid* context, seasonConfig season1) : season(season1){

	this->context = context;

}

void finalStudents::display(){
	system("CLS");
	int index, count = 0;
	for (int i = 0; i < season.studentList.count(); i++)
		cout << i << " :  " << season.studentList.get(i).name.get() << "\n";
	cout << "Choose student by index \n";
	do{
		cin >> index;
		if (index > season.studentList.count())
			cout << "Wrong index try again \n";
	} while (index > season.studentList.count());
	for (int i = 0; i < season.studentList.get(index).FinalCourses.count(); i++)
	{
		cout << season.studentList.get(index).FinalCourses.get(i).name.get() << "\n";
		count++;
	}
	cout << "Total num of courses: " << count << "\n";
	cout << "Press b for back \n";
	cout << "Press q to quit \n";
}


bool finalStudents::checkData(int input){
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

