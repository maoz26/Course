#ifndef Terminals_H
#define Terminals_H
#include "CSList.h"
#include "seasonConfig.h"
#include <iostream>
using namespace std;

class Terminals : public CSList{

public:
	seasonConfig season;
	Terminals(CourseBid* context, seasonConfig season1);
	string get(int index);
	void select(int index);
	void myDelete(int index);
	void add(int index);
	int countList();
	void returnState();

};



#endif
