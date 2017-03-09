#include "FormulaEdit.h"
#include "Lexer.h"
#include "EnterSec.h"
#include <string>
#include <iostream>
#include "Terminal.h"
using namespace std;

FormulaEdit::FormulaEdit(CourseBid* context, seasonConfig season1) : season(season1) {
	this->context = context;
}
void FormulaEdit::display(){
	cout << "Formula :  " << season.formula.get() << "\n";
	cout << "\n Optioins:  \n";
	cout << "Press 1 to Edit \n";
	cout << "Press b to back  \n";
}

bool FormulaEdit::checkData(int input){
	switch (input)
	{
	case '1':
		edit();
		break;
	case 'b':
		returnState();
		break;
	case 'q':
	case 'Q':
		return false;
	default:
		break;

	};
	return true;

}
void FormulaEdit::edit(){
	Lexer lexer;
	string experssion;
	cout << "Please enter Arithmetic experssion \n";
	cin >> experssion;
	lexer.setExpr(experssion);
	lexer.tokenize();
	season.formula.set(experssion);
};

void FormulaEdit::returnState(){
	EnterSec* state = new EnterSec(context, season);
	context->setState(state);
}