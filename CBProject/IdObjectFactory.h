#ifndef IdObjectFactory_H
#define IdObjectFactory_H
#include <iostream>
#include "IStorage.h"

using namespace std;


class IdObjectFactory{

public:
	IStorage* _storage;

public:

	IdObjectFactory(IStorage &storage) : _storage(&storage) {};

	template<class T>
	T construct(int id) {
		return  T(id, *this);
	};

	template<class T>
	T allocate() {
		int idObj = _storage->getLastId() + 1;
		return  T(idObj, *this);

	};

	IStorage* getStorage() {
		IStorage* temp = _storage;
		return _storage;
	};

};


#endif