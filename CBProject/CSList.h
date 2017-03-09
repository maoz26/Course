//CSList present Courses\Students list.

#ifndef CSList_H
#define CSList_H
#include "UserInterface.h"
#include <string>
#include <iostream>
using namespace std;

class CSList : public UserInterface {

public:
	int cur_sel;
	CSList();
	bool checkData(int input);
	void display();
	virtual string get(int index) = 0;
	virtual void select(int index) = 0;
	virtual void myDelete(int index) = 0;
	virtual void add(int index) = 0;
	virtual int countList() = 0;
	virtual void returnState() = 0;


};


#endif



