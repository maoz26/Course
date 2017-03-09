#include "CoursesPlacement.h"
#include <exception>
finalCourses::finalCourses(CourseBid* context, seasonConfig season1) : season(season1){

	this->context = context;

}

void finalCourses::display(){
	system("CLS");
	int index, count = 0;
	for (int i = 0; i < season.courseList.count(); i++)
		cout << i << " :  " << season.courseList.get(i).name.get() << "\n";
	cout << "Choose course by index \n";	
	do{
		cin >> index;
		if (index > season.courseList.count())
			cout<<"Wrong index try again \n";
	} while (index > season.courseList.count());
	int idCourse = season.courseList.get(index).get_id();
	for (int i = 0; i < season.studentList.count(); i++)
	{
		for (int j = 0; j < season.studentList.get(i).FinalCourses.count(); j++){
			int y = season.studentList.get(i).FinalCourses.count();
			int x = season.studentList.get(i).FinalCourses.get(j).get_id();
			string name = season.studentList.get(i).name.get();
			if (idCourse == season.studentList.get(i).FinalCourses.get(j).get_id())
			{
				cout << season.studentList.get(i).name.get() << "\n";
				count++;
			}
		}
	}
	cout << "Total num of students:  " << count << "\n";
	cout << "Press b for back \n";
	cout << "Press q to quit \n";
}


bool finalCourses::checkData(int input){
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

