#ifndef Course_H
#define Course_H
#include <iostream>
#include "RefListField.h"
#include "NonRefField.h"
using namespace std;

class Course : public IdObj 
{
public:
	Course(int id, IdObjectFactory &factory) : IdObj(id, factory),
		id(*this), name(*this), description(*this), teachingHours(*this), pre(*this), maxNumberOfStudents(*this), points(*this)
	{}
		NonRefField<string, 0> name;
		NonRefField<string, 1> description;
		NonRefField<int, 2> teachingHours;
		RefListField <Course, 3> pre;
		NonRefField<int, 4> maxNumberOfStudents;
		NonRefField<int, 5> id;
		NonRefField<int, 6> points;
	
};

#endif