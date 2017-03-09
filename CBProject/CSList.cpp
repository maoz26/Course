#include "CSList.h"
#include "seasonConfig.h"
#include <iostream>
#include <string>
using namespace std;
#include <conio.h>
#include <cstdlib>
#include "EnterSec.h"

CSList::CSList() : cur_sel(0){
}

bool CSList::checkData(int input){
	try{

		switch (input)
		{
		case '1':
			this->select(cur_sel);
			break;
		case '2':
			cout << "Enter the index that you want to delete: \n";
			cin >> cur_sel;
			this->myDelete(cur_sel);
			cout << "Deleted successfully \n";
			break;
		case '3':
			this->add(cur_sel);
			cout << "Added successfully \n";
			break;
		case 'b':
			this->returnState();
			break;
		
		case 'q':
		case 'Q':
			return false;
		default:
			break;

		};

	}
	catch (exception &e){
		cout << "*** " << e.what() << " *** \n";
	}
	return true;
};

void CSList::display()  {

	cout << "\n" << "\n";
	cout << "Opitions:  \n";
	cout << "Press 1 to Edit \n";
	cout << "Press 2 to Delete \n";
	cout << "Press 3 to Add  \n";
	cout << "Press b to back  \n\n";
	cout << "Here is the list:  \n";
	for (int i = 0; i < countList(); i++)
			cout << i << " :  " << this->get(i) << "\n";
	cout << "Total:  " << this->countList() << "\n";


}


