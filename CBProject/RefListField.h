#ifndef RefListField_H
#define RefListField_H
#include <algorithm>
#include <iostream>
#include "IdObj.h"
#include <vector>
using namespace std;

template<class T, int idField>
class RefListField {

public:
	IdObj _obj;
	int _idField;
	string field;
	string combId;
	vector<string> strVec;
	RefListField(IdObj obj) : _idField(idField), _obj(obj) {
	};

	void initVar(){

		string token1;
		combId = to_string(_obj.idObj) + "," + to_string(_idField);
		IStorage* temp = _obj.getFactory().getStorage();
		field = temp->get(combId);


		std::istringstream ss1(field);
		strVec.clear();
		while (getline(ss1, token1, ','))
		{
			this->strVec.push_back(token1);
		}
	}
	int count() {

		initVar();
		return this->strVec.size();

	};
	/*Add T to the end of the list not necessary index*/
	void add(T obj){
		string value;
		int exist = 0;
		string token1;
		initVar();
		//create IdObj that will be equal to obj
		IdObj newObj = obj;
		try{
			std::istringstream ss(field);
			while (getline(ss, token1, ','))
			{
				if (atoi(token1.c_str()) == newObj.get_id())
					exist = 1;
			}
			if (exist){
				/*cout << "Already exist \n";*/
				int x = 5;
			}

			else
			{
				/*check if the field is empty*/
				if (field == "")
				{
					value = to_string(newObj.get_id());
				}
				else
				{
					value = field + "," + to_string(newObj.get_id());
				}
				this->_obj.getFactory().getStorage()->set(this->combId, value);

			}
		}
		catch (string str){
		}
	};

	void remove(int index){
		initVar();
		string value;
		if (index > count())
			cout << "Invalid index \n";
		else
		{


			strVec.erase(strVec.begin() + index);

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
			cout << "The new value: " << value << "\n";
			_obj.getFactory().getStorage()->set(combId, value);
		}
	};


	T get(int index){

		if (index > count())
			throw exception("Invalid index");

		else{
			initVar();
			return  T(atoi(strVec[index].c_str()), _obj.getFactory());
		}


	};

	T allocateAndAdd(){
		T temp = _obj.getFactory().allocate<T>();
		add(temp);
		return temp;
	}



};

#endif