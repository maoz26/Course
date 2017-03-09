#ifndef StudentsListEdit_H
#define StudentsListEdit_H
#include "CSList.h"
#include "seasonConfig.h"
#include <string.h>
#include <iostream>
using namespace std;

class StudentsListEdit : public CSList{
public:
	seasonConfig season;
	StudentsListEdit(CourseBid* context, seasonConfig season1);
	string get(int index);

	void  select(int index);

	void myDelete(int index);

	void add(int index);

	int countList();

	void returnState();

	void Shibetz_final_courses();

};

#endif