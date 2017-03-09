#ifndef System_H
#define System_H
#include "UserInterface.h"
#include "FileStorage.h"
#include "IdObjectFactory.h"
#include "seasonConfig.h"
class System : public UserInterface{
public:

	int idterminal;

	FileStorage storage;
	IdObjectFactory factory;
	seasonConfig season;

	System(FileStorage storage1, IdObjectFactory factory1, seasonConfig season1);

	bool checkData(int input);
	void checkSystem();

	void display();
};

#endif