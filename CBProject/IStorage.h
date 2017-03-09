#ifndef IStorage_H
#define IStorage_H

#include <iostream>
using namespace std;
#include <string>


class IStorage{
public:
	virtual string get(string id) = 0;
	virtual void set(string id, string value) = 0;
	virtual int getLastId() = 0;

};

#endif