	#include "EnterSec.h"
	#include "CourseListEdit.h"
	#include "StudentsListEdit.h"
	#include "FormulaEdit.h"
	#include "Terminals.h"
	#include "Placement_Calculate.h"
	#include <iostream>
	#include <string>
	using namespace std;


	EnterSec::EnterSec(CourseBid* context, seasonConfig season1) : season(season1){
	this->context = context;
	}


	void EnterSec::display(){
	cout << "Press 1 to Courses \n";
	cout << "Press 2 to Students \n";
	cout << "Press 3 to Formula \n";
	cout << "Press 4 to Terminals \n";
	cout << "Press 5 to Show results - students and courses \n";
	cout << "Press q to quit \n";

	}

	bool EnterSec::checkData(int input){
	switch (input)
	{
	case '1':
	{
		CourseListEdit* state1 = new CourseListEdit(context, season);
		context->setState(state1);
		break;
	}
	case '2':
	{
		StudentsListEdit* state2 = new StudentsListEdit(context, season);
		context->setState(state2);
		break;
	}
	case '3':
	{
		FormulaEdit* state3 = new FormulaEdit(context, season);
		context->setState(state3);
		break;
	}
	case '4':
	{
		Terminals* state3 = new Terminals(context, season);
		context->setState(state3);
		break;
	}
	case '5':
	{
		Placement* state4 = new Placement(context, season);
		context->setState(state4);
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

