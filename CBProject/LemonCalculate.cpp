#include "LemonCalculate.h"
#include "seasonConfig.h"
#include <string>
#include <iostream>
#include <vector>
using namespace lemon;
using namespace std;
#include <lemon/glpk.h>
#include <lemon/lp.h>

calculate::calculate(FileStorage storage1, IdObjectFactory factory1) : storage(storage1), factory(factory1){}
void calculate::assignedCoursestoStudents(){

	seasonConfig season = factory.construct<seasonConfig>(0);
	Lp lp;
	Lp::Expr e1, e2, e;
	Lp::Constr c = e1 <= e2;
	int m, n, x;
	m = season.studentList.count();
	n = season.courseList.count();
	Lp::Expr* expr = new Lp::Expr[sizeof n];
	Lp::Col** matrix = new Lp::Col*[sizeof m];
	for (int i = 0; i < m; i++)
		matrix[i] = new Lp::Col[sizeof n];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Lp::Col x11 = lp.addCol();
			lp.colLowerBound(x11, 0);
			lp.colUpperBound(x11, 1);
			matrix[i][j] = x11;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int limit;
		limit = season.courseList.get(i).maxNumberOfStudents.get();
		Lp::Expr e1;

		for (int x = 0; x < m; x++)
			e1 += matrix[x][i];

		Lp::Constr c = e1 <= limit;
		lp.addRow(c);
	}
	int c11, check = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
		for (x = 0; x < season.studentList.get(i).BidCourses.count(); x++)
		{
			int idcourse = season.courseList.get(j).id.get();
			int bidCourse = season.studentList.get(i).BidCourses.get(x).id.get();
			if (idcourse == bidCourse){
				c11 = season.studentList.get(i).BidCourses.get(x).points.get();
			}
		}
		
		e += (c11*matrix[i][j]);
		}

	lp.max();
	lp.obj(e);
	lp.solve();

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++)
		{
		
			if (lp.primal(matrix[i][j]) == 1){
				Course c = season.courseList.get(j);
			
				season.studentList.get(i).FinalCourses.add(c);

			}
		}
	
	}
}