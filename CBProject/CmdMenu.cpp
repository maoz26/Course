#include <vector>
#include <string.h>
#include "FileStorage.h"
#include "IdObjectFactory.h"
#include "Terminal.h"
#include "seasonConfig.h"
#include "EnterSec.h"
#include <iostream>
#include "System.h"
using namespace std;

int main()

{
	int input;
	cout << "Welcome to CourseBid program \n\n";

	FileStorage storage("db.txt");
	IdObjectFactory factory(storage);
	seasonConfig season(0, factory);
	Terminal terminal = season.getFactory().allocate<Terminal>();
	CourseBid* context = new CourseBid();
	cout << "Press 1 to Studnet \n";
	cout << "Press 2 to System \n";
	do{
		cin >> input;
		if (input == 2)
		{
			EnterSec* state1 = new EnterSec(context, season);
			context->setState(state1);
		}
		else
			if (input == 1)
			{
			System* state2 = new System(storage, factory,season);
			context->setState(state2);
			}
	} while (input != 1 && input != 2);

	context->run();
	return 1;
};