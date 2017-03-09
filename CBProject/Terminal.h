#ifndef Terminal_H
#define Terminal_H
#include "NonRefField.h"
using namespace std;

class Terminal : public IdObj {
public:
	Terminal(int id, IdObjectFactory &factory) : IdObj(id, factory),
		id(*this), password(*this), status(*this)	{}

	NonRefField<string, 0> id;
	NonRefField<string, 1> password;
	NonRefField<int, 2> status;


};

#endif