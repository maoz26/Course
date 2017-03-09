#ifndef StudentsOffer_H
#define StudentsOffer_H
#include "UserInterface.h"
#include "seasonConfig.h"
#include "Student.h"
#include  "Lexer.h"
#include <string>
#include <iostream>
using namespace std;

class StudentsOffer : public UserInterface{
public:
	seasonConfig season;
	Student student;
	int cur_sel;
	int points;
	int cur_points;
	Lexer lexer;
	int flag;
	StudentsOffer(CourseBid* context, seasonConfig season1, Student student1);

	void display();


	bool checkData(int input);


	void bidPoints(int cur_sel);

};
#endif