#include "CourseBid.h"
#include "UserInterface.h"
#include <string>
#include <iostream>
using namespace std;
#include <conio.h>
#include <cstdlib>
#include <exception>
void CourseBid::setState(UserInterface* state1){
	state = state1;
}

void CourseBid::run(){
	try{

		do
		{
			state->display();
		} while (state->checkData(_getch()));

	}
	catch (exception e){
		cout << e.what() << "\n";
	}

};

