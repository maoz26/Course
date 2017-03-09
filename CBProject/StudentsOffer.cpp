#include "StudentsOffer.h"
#include "EntryDisp.h"
#include "UserInterface.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <exception>

StudentsOffer::StudentsOffer(CourseBid* context, seasonConfig season1, Student student1) : season(season1), student(student1), cur_sel(0)
{
	this->context = context;
	flag = 0;
	Lexer lexer;
	string formula;
	int completetd = student.completed.count();
	formula = season.formula.get();

	if (formula == ""){
		throw exception("No points -> Come back Later");
		exit(0);
	}
	lexer.setExpr(formula);
	lexer.tokenize();
	points = lexer.getExpr(completetd);
	cur_points = points;


};

void StudentsOffer::display(){
	system("CLS");
	
	int check = 0;
	
	if (flag == 0)
	{

		for (int i = 0; i < season.courseList.count(); i++){
			Course course = season.courseList.get(i);
			course.points.set(0);
			
			if (course.pre.count() == 0){
				check = 1;
			}
			else
			{
				for (int j = 0; j < course.pre.count(); j++){
					check = 0;
					for (int x = 0; x < student.completed.count(); x++)
					{
					
						if (course.pre.get(j).id.get() == student.completed.get(x).id.get())
						{
							check = 1;
						}

					}
					
					if (check == 0)
						break;
				}

			}
		
			if (check)
			{
				
				Course course = season.courseList.get(i);
			
				student.BidCourses.add(course);

			}

		}
	}
	cout << "POINTS: ";
	cout << points << "\n";
	cout << "CURRENT POINTS: ";
	cout << cur_points << "\n";
	for (int i = 0; i < student.BidCourses.count(); i++)
			cout << i << " :  " << student.BidCourses.get(i).name.get() << "\n";

	cout << "\n Options: \n";
	cout << "Press 1 to insert points to course \n";
	cout << "Press q to quit \n";
	flag = 1;

};


bool StudentsOffer::checkData(int input){
	switch (input)
	{
	case '1':
	{
		try{
			bidPoints(cur_sel);
		}
		catch (exception e)
		{
			system("CLS");
			cout << e.what() << "\n";
		}
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


void StudentsOffer::bidPoints(int cur_sel) {
	cout << "Enter points:  \n";
	int input;
	cin >> input;
	int curr = 0;
	
	if (input <= cur_points)
	{
		int y = cur_sel;

		student.BidCourses.get(cur_sel).points.set(input);


		for (int i = 0; i < student.BidCourses.count(); i++)
		{
			int x = student.BidCourses.get(i).points.get();

			curr = curr + student.BidCourses.get(i).points.get();
		}

		cout << "Current POINTS : " << points - curr << "\n";

		cur_points = points - curr;
	}

	else{
		throw exception("***NOT ENOUGH POINTS TO BID -> REBID***");
	}

}