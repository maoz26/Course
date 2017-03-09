#pragma once
#ifndef CourseBid_H
#define CourseBid_H

class UserInterface;

class CourseBid{
public:

	UserInterface* state;

	void setState(UserInterface* state1);

	void run();

};


#endif