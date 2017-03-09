#include "Terminals.h"
#include "TerminalEnter.h"
#include <string>
#include <iostream>
using namespace std;
#include <conio.h>
#include <cstdlib>
#include <exception>
#include "EnterSec.h"
Terminals::Terminals(CourseBid* context, seasonConfig season1) : season(season1){
	this->context = context;
}

int Terminals::countList(){
	return season.terminalList.count();
}

string Terminals::get(int index){
	if (season.terminalList.count() == 0)
		throw exception("The list is empty");
	string value;
	value = season.terminalList.get(index).id.get() + "," + to_string(season.terminalList.get(index).status.get());
	return value;
}


void Terminals::select(int index){
	
	if (season.terminalList.count() == 0)
		throw exception("The list is empty");
	cout << "Enter the index that you want to edit: \n";
	cin >> index;
	TerminalEnter* state = new TerminalEnter(context, season, season.terminalList.get(index));
	context->setState(state);
}

void Terminals::myDelete(int index)
{

	if (season.terminalList.count() == 0)
		throw exception("The list is empty");
	int input;
	cout << "Are you sure you want to delete ? \n";
	cout << "if yes enter '1' otherwise enter '0' \n";
	input = _getch();
	if (input)
		season.terminalList.remove(index);
	else
		cout << "Not deleted \n";

}

void Terminals::add(int index){
	string input, val;
	cout << "Please insert the following deatils: \n";
	Terminal newTerminal = season.terminalList.allocateAndAdd();
	season.terminalList.add(newTerminal);
	TerminalEnter* state = new TerminalEnter(context, season, newTerminal);
	for (int i = 0; i < state->getFieldCount(); i++)
		state->edit(i);
	context->setState(state);


}

void Terminals::returnState(){
	EnterSec* state = new EnterSec(context, season);
	context->setState(state);

}