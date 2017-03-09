#ifndef IdObj_H
#define IdObj_H
#include <iostream>
#include "IdObjectFactory.h"
using namespace std;

class IdObj{
public:
	int idObj;
	IdObjectFactory _factory;

	IdObj(int id, IdObjectFactory &factory) : idObj(id), _factory(factory){};
	int get_id() { return idObj; };
	IdObjectFactory getFactory() { return _factory; };

};

#endif 