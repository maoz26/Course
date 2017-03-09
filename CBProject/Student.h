#ifndef Student_H
#define Student_H
#include <iostream>
#include "Course.h"
#include "NonRefField.h"
#include "IdObj.h"
#include "RefListField.h"

using namespace std;

class Student : public IdObj {
public:
	Student(int id, IdObjectFactory &factory)
		: IdObj(id, factory),
		status(*this), name(*this), completed(*this), id(*this), BidCourses(*this), FinalCourses(*this)
	{

	}

	NonRefField<int, 0> status;
	NonRefField<string, 1> name;
	RefListField<Course, 2> completed;
	NonRefField<string, 3> id;
	RefListField<Course, 4> BidCourses;
	RefListField<Course, 5 > FinalCourses;

};

#endif

