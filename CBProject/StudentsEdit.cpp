
#include "StudentsEdit.h"
#include "StudentsListEdit.h"
#include "EntryDisp.h"
#include "CompletedState.h"
#include "Student.h"
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;


StudentsEdit::StudentsEdit(CourseBid* context1, seasonConfig season1, Student student1) :season(season1), studnet(student1){
	this->context = context1;
}

int StudentsEdit::getFieldCount() {
	return 4;
};

string StudentsEdit::getCaption(int i){
	if (i == 0)
		return "status";
	if (i == 1)
		return "name";
	if (i == 2)
		return "completed";
	if (i == 3)
		return "id";
};

string StudentsEdit::getValue(int i){

	if (i == 0)
	{
		cout << "Status: ";
		return to_string(studnet.status.get());
	}
	if (i == 1)
	{
		cout << "Name: ";
		return studnet.name.get();
	}
	if (i == 2){
		string value;
		int count = studnet.completed.count();
		vector<std::string> strVec;
		cout << "Completed courses: ";
		for (int i = 0; i < count; i++)
		{
			strVec.push_back(to_string(studnet.completed.get(i).id.get()));
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
		return value;
	}
	if (i == 3){
		cout << "Id: ";
		return studnet.id.get();
	}
}

void StudentsEdit::edit(int i){
	if (i == 0)
	{
		int val;
		cout << "Please Enter new status \n";
		cin >> val;
		this->studnet.status.set(val);
	}
	if (i == 1)
	{
		string val;
		cout << "Please Enter new name \n";
		cin >> val;
		this->studnet.name.set(val);
	}
	
	if (i == 2){
		CombState* state = new CombState(context, season, studnet.get_id());
		context->setState(state);
	}

	if (i == 3)
	{
		string val;
		cout << "Please Enter new id  \n";
		cin >> val;
		this->studnet.id.set(val);
	}
}

void StudentsEdit::entryReturnState(){
	StudentsListEdit* state = new StudentsListEdit(context, season);
	context->setState(state);
}