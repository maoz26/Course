#pragma once
#ifndef _sesonConfig_
#define _seasonConfig_
#include "NonRefField.h"
#include "RefListField.h"
#include "Course.h"
#include "Student.h"
#include "Terminal.h"
#include <iostream>
#include <string>
using namespace std;
class seasonConfig : public IdObj {
public:
	seasonConfig(int id, IdObjectFactory &factory) : IdObj(id, factory),
		courseList(*this), studentList(*this), formula(*this), terminalList(*this)
	{}
	RefListField <Course, 0> courseList;
	RefListField <Student, 1> studentList;
	NonRefField <string, 2> formula;
	RefListField <Terminal, 1> terminalList;
};

#endif
