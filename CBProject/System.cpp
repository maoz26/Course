#include "System.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "LemonCalculate.h"
#include "FileStorage.h"
#include "IdObjectFactory.h"
#include "seasonConfig.h"
#include "StudentsEnter.h"
using namespace std;


System::System(FileStorage storage1, IdObjectFactory factory1, seasonConfig season1) : storage(storage1), factory(factory1),season(season1){
	this->context = context;
}

bool System::checkData(int input){
	switch (input)
	{
	case '1':{
		
		studentsEnter* state = new studentsEnter(context, season);
		context->setState(state);
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

void System::display(){
	system("CLS");
	string temp_str, token1, token2, input, line;
	cout << "Enter Admin password \n";
	cin >> input;
	string name = "admin";
	if (input == "admin")
	{
		cout << "The system checking is starting... \n";
	}
	else
		return;
	checkSystem();
}


void System::checkSystem(){
//	calculate myCal(storage, factory);
//	myCal.assignedCoursestoStudents();
	seasonConfig season_input = factory.construct<seasonConfig>(0);
	FileStorage storage_output("db_output.txt");
	IdObjectFactory factory_output(storage_output);
	seasonConfig season_output = factory_output.construct<seasonConfig>(0);
	int equal = 1;
	int check = season_output.studentList.count();
	for (int j = 0; j < season_output.studentList.count(); j++)
	{
		for (int i = 0; i < season_output.studentList.get(j).FinalCourses.count(); i++)
		{
			int in = season_input.studentList.get(j).FinalCourses.get(i).id.get();
			int out = season_output.studentList.get(j).FinalCourses.get(i).id.get();
			if (in != out)
			{
				cout << "This Terminal is not Good \n";
				equal = 0;
				break;
			}
		}
	}

	if (equal)
	{
		cout << "***The check was completed succssefully*** \n\n";
		cout << "Press 1 to student \n";
		cout << "Press q to quit \n";
	}
}
