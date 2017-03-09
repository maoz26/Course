#ifndef TerminalEnter_H
#define TerminalEnter_H
#include "EntryDisp.h"
#include "seasonConfig.h"
#include <string.h>
#include <iostream>
using namespace std;

class TerminalEnter : public EntryDisp {
public:
	int cur_sel;
	seasonConfig season;
	Terminal terminal;
	TerminalEnter(CourseBid* context, seasonConfig season1, Terminal terminal1);
	int getFieldCount();
	string getCaption(int index);
	string getValue(int index);
	void edit(int index);
	void entryReturnState();

};

#endif

