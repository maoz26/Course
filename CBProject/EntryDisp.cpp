#include "EntryDisp.h"
#include <iostream>
#include <string>
using namespace std;

EntryDisp::EntryDisp() : cur_sel(0) {}

bool EntryDisp::checkData(int input){
	switch (input)
	{
	case '1':
		cout << endl;
		for (int i = 0; i < this->getFieldCount();i++)
			cout << this->getValue(i) << "\n";
		cout << endl;
		break;
	case '2':
		cout << "Enter which attribute you want to edit \n";
		cin >> cur_sel;
		edit(cur_sel);
		break;
	
	case 'b':
		entryReturnState();
		break;
	case 'q':
	case 'Q':
		return false;
	default:
		break;

	};
	return true;
};

void EntryDisp::display(){

	cout << "Opitions:  \n";
	cout << "Press 1 for details \n";
	cout << "Press 2 to edit \n";
	cout << "Press b to back \n";
	cout << "Attributes: \n\n";
	int count = this->getFieldCount();
	for (int i = 0; i < count; i++)
			cout << i << " :  " << this->getCaption(i) << "\n";
	cout << endl;
};