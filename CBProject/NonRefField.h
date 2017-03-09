#ifndef NonRefField_H
#define NonRefField_H
#include <iostream>
#include <sstream>
#include "IdObj.h"
using namespace std;

template<class T, int idField>
class NonRefField{

public:
	IdObj _obj;
	T val;				//The type of field in object .
	int _idField;		//The identity of field in object 
	string field;
	string combId;

	NonRefField(IdObj obj) : _obj(obj), _idField(idField){};

	void initVar() {
		this->combId = to_string(_obj.idObj) + "," + to_string(_idField);
		this->field = _obj.getFactory().getStorage()->get(combId);

	}

	T get() {
		initVar();
		T tempObj;
		stringstream buffer(field);
		buffer >> tempObj;
		return tempObj;
	};

	void set(T value){
		initVar();
		stringstream buffer;
		buffer << value;
		_obj.getFactory().getStorage()->set(combId, buffer.str());
	};



};

#endif
