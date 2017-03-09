#include "StudentsEnter.h"
#include "Terminal.h"
#include "StudentsOffer.h"
#include <string>
#include <iostream>

using namespace std;

studentsEnter::studentsEnter(CourseBid* context, seasonConfig season1) :season(season1) {
	this->context = context;
}

void studentsEnter::display(){
	system("CLS");
	cout << "Press 1 to Enter password \n";
	cout << "Press q to quit \n";

}

bool studentsEnter::checkData(int input){
	try{

		switch (input)
		{
		case '1':{
			checkPassword();
			break;
		}
		case 'q':
		case 'Q':
			return false;
		default:
			break;
		};
	}
	catch (exception e){
		cout << e.what() << "\n";
	}
	return true;
};

void studentsEnter::checkPassword(){
	int password;
	cout << "password \n";
	cin >> password;
	int idobj, check = 0;
	if (wrongPassword < 4)
	{
		for (int i = 0; i < season.studentList.count(); i++)
		{
			string id = season.studentList.get(i).id.get();
			if (password == atoi(id.c_str()))
			{
				idobj = season.studentList.get(i).get_id();
				Student student = season.studentList.get(i);
	
				StudentsOffer* state1 = new StudentsOffer(context, season, student);
				context->setState(state1);
				check = 1;
			}
		}
		if (check == 0)
			cout << "WRONG PASSWORD \n";
	}
	wrongPassword++;
	if (wrongPassword == 3)
	{
		cout << "TERMINAL IS LOCKED \n";
		season.getFactory().construct<Terminal>(0).status.set(0);
		exit(0);
	}
}