#ifndef CompletedState_H
#define CompletedState_H
#include "UserInterface.h"
#include "seasonConfig.h"
#include <string.h>
#include <iostream>
using namespace std;

class CombState : public UserInterface{

public:
	seasonConfig season;
	int idobj;
	int cur_sel;

	CombState(CourseBid* context1, seasonConfig season1, int idobj1);

	bool checkData(int input);

	void display();

	void add(int index, int idobj);

	void remove(int index, int idobj);

	void returnStudentEnrty();
};

#endif