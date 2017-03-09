#ifndef StudentsEdit_H
#define StudentsEdit_H
#include "EntryDisp.h"
#include "seasonConfig.h"
#include <string>
#include <iostream>
using namespace std;

class StudentsEdit : public EntryDisp {

public:

	Student studnet;

	seasonConfig season;

	StudentsEdit(CourseBid* context1, seasonConfig season1, Student student1);

	int getFieldCount();

	string getCaption(int i);

	string getValue(int i);

	void edit(int i);

	void entryReturnState();
};


#endif 