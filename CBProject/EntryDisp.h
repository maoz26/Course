#ifndef EntryDisp_H
#define EntryDisp_H
#include "UserInterface.h"
#include <string>
#include <iostream>
using namespace std;


class EntryDisp : public UserInterface {

public:
	int cur_sel;

	EntryDisp();

	bool checkData(int input);

	void display();

	virtual int getFieldCount() = 0;

	virtual string getCaption(int index) = 0;

	virtual string getValue(int index) = 0;

	virtual void edit(int index) = 0;

	virtual void entryReturnState() = 0;
};


#endif