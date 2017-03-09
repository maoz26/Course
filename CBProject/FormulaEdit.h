#ifndef FormulaEdit_H
#define FormulaEdit_H
#include "UserInterface.h"
#include "seasonConfig.h"


class FormulaEdit : public UserInterface {
public:
	seasonConfig season;

	FormulaEdit(CourseBid* context, seasonConfig season1);

	void display();

	bool checkData(int input);

	void edit();

	void returnState();

};


#endif