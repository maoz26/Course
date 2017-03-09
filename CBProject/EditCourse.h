#ifndef Edit_Course_H
#define Edit_Course_H
#include "EntryDisp.h"
#include "seasonConfig.h"
#include <string.h>
#include <iostream>
using namespace std;


class EditCourse : public EntryDisp {
public:
	Course course;
	seasonConfig season;

	EditCourse(CourseBid* context1, seasonConfig season1, Course course1);

	bool Circle(vector<string>&vec);

	int getFieldCount();

	void edit(int i);

	string getCaption(int i);

	string getValue(int i);

	void entryReturnState();
};


#endif 
