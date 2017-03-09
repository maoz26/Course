#include "EditCourse.h"
#include <lemon/maps.h>
#include <lemon/list_graph.h>
#include <lemon/Bfs.h>
#include <fstream>
#include <string>
#include <iostream>
#include "Course.h"
#include "PreCourses.h"
#include "CourseListEdit.h"
using namespace lemon;
using namespace std;

EditCourse::EditCourse(CourseBid* context1, seasonConfig season1, Course course1) : course(course1), season(season1){
	this->context = context1;
}


int EditCourse::getFieldCount() {
	return 6;
};



void EditCourse::edit(int i)
{
	if (i == 0)
	{
		string val;
		cout << "Please Enter new name \n";
		cin >> val;
		course.name.set(val);

	}
	if (i == 1)
	{
		string val;
		cout << "Please Enter new description  \n";
		cin >> val;
		course.description.set(val);

	}
	if (i == 2)
	{
		int val;
		cout << "Please Enter new teaching hours \n";
		cin >> val;
		course.teachingHours.set(val);

	}


	if (i == 4)
	{
		int val;
		cout << "Please Enter new max students  \n";
		cin >> val;
		course.maxNumberOfStudents.set(val);

	}

	if (i == 3){
		PreCourses* state = new PreCourses(context, season, course.get_id());
		context->setState(state);
	}

	if (i == 5){
		int val;
		cout << "Please Enter id  \n";
		cin >> val;
		course.id.set(val);

	}


}

string EditCourse::getCaption(int i){
	if (i == 0)
		return "name";
	if (i == 1)
		return "description";
	if (i == 2)
		return "teachingHours";
	if (i == 3)
		return "pre";
	if (i == 4)
		return "maxNumberOfStudents";
	if (i == 5)
		return "id";

};

string EditCourse::getValue(int i){
	if (i == 0){
		cout << "Course name: ";
		return course.name.get();
	}

	if (i == 1)
	{
		cout << "Course description: ";
		return course.description.get();
	}

	if (i == 2)
	{
		cout << "Course teaching hours: ";
		return to_string(course.teachingHours.get());
	}

	if (i == 3){

		string value;
		int count = course.pre.count();
		vector<std::string> strVec;
		cout << "Pre courses: ";
		if (count)
		{
			for (int i = 0; i < count; i++)
			{
				strVec.push_back(to_string(course.pre.get(i).id.get()));

			}
			for (size_t i = 0; i < strVec.size(); i++)
			{
				if (i + 1 == strVec.size())
					value = value + "," + strVec[i];
				else
					if (i == 0)
						value = strVec[i];
					else
						value = value + "," + strVec[i];
			}
		}
		else
		{
			value = "No pre courses";
		}

		return value;
	}
	if (i == 4)
	{
		cout << "Course max number of students: ";
		return to_string(course.maxNumberOfStudents.get());
	}
	if (i == 5)
	{
		cout << "Course id is: ";
		return to_string(course.id.get());
		cout << endl << endl;
	}
}


bool EditCourse::Circle(vector<string> &vec)
{
	string line;
	string word1, word2;
	ListDigraph g;
	ListDigraph::Node x;
	ListDigraph::Node y;
	Bfs<ListDigraph> bfs(g);
	CrossRefMap<ListDigraph, ListDigraph::Node, string> names(g);

	int numberOfLines;

	numberOfLines = vec.size();

	for (int i = 0; i < numberOfLines; i++)
	{
		string val;
		std::istringstream ss(vec[i]);
		getline(ss, word1, ' ');
		getline(ss, word2, ' ');

		cout << word1 << " " << word2 << "\n";

		if (names(word1) == INVALID){

			x = g.addNode();
			names.set(x, word1);

		}
		else
			x = names(word1);


		if (names(word2) == INVALID) 
		{

			y = g.addNode();
			names.set(y, word2);
		}
		else
			y = names(word2);

		bfs.run(y);
		if (bfs.reached(x) && bfs.dist(x)) {
			return true;
			cout << numberOfLines << "\n";
			for (ListDigraph::Node p = x; p != INVALID; p = bfs.predNode(p))
				std::cout << names[p] << " ";
			std::cout << std::endl;
		}

		else

			ListDigraph::Arc arc = g.addArc(x, y);
	}

	return false;
};

void EditCourse::entryReturnState(){
	CourseListEdit* state = new CourseListEdit(context, season);
	context->setState(state);
}