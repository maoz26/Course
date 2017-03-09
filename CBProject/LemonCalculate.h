#ifndef LemonCalculate_H
#define LemonCalculate_H
#include <lemon/glpk.h>
#include <lemon/lp.h>
#include "FileStorage.h"
#include "IdObjectFactory.h"
#include <iostream>
#include "seasonConfig.h"
using namespace lemon;
using namespace std;
class calculate{

	FileStorage storage;
	IdObjectFactory factory;
public:
	calculate(FileStorage storage, IdObjectFactory factory);
	void assignedCoursestoStudents();

};

#endif