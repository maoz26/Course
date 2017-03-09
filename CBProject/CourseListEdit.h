#ifndef CourseListEdit_H
#define CourseListEdit_H
#include "CSList.h"
#include "seasonConfig.h"
#include <string.h>
#include <iostream>
using namespace std;

class CourseListEdit : public CSList {

public:

	seasonConfig season;

	CourseListEdit(CourseBid* context, seasonConfig season1);

	string get(int index);;

	void  select(int index);;

	void myDelete(int index);

	void add(int index);

	int countList();

	void returnState();

};


#endif