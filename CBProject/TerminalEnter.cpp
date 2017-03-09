#include "TerminalEnter.h"
#include "Terminals.h"
#include <string>
#include <iostream>
using namespace std;

TerminalEnter::TerminalEnter(CourseBid* context, seasonConfig season1, Terminal terminal1) : season(season), terminal(terminal1){
	this->context = context;
}

int  TerminalEnter::getFieldCount(){
	return 3;
};

string TerminalEnter::getCaption(int index){
	if (index == 0)
		return "id";
	if (index == 1)
		return "password";
	if (index == 2)
		return "status";

}

string TerminalEnter::getValue(int index){
	if (index == 0)
		return terminal.id.get();
	if (index == 1)
		return terminal.password.get();
	if (index == 2)
		return to_string(terminal.status.get());
};

void TerminalEnter::edit(int index){
	string value;
	int stat;
	if (index == 0)
	{
		cout << "Enter new id  \n";
		cin >> value;
		terminal.id.set(value);
	}
	if (index == 1)
	{
		cout << "Enter new password  \n";
		cin >> value;
		terminal.password.set(value);
	}
	if (index == 2)
	{
		cout << "Enter new status \n1-work, 0-not work  \n";
		cin >> stat;
		terminal.status.set(stat);
	}
}

void TerminalEnter::entryReturnState(){
	Terminals* state = new Terminals(context, season);
	context->setState(state);
}