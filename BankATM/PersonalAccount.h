#include <iostream>
#include <string>
#include "Account.h"
#ifndef PERSONALACCOUNT_H_
#define PERSONALACCOUNT_H_

class PersonalAccount: public Account {
private:
	string firstName;
	string lastName;
	int SSN; //9 digit 
	int generateSSN();

public:
	PersonalAccount(string fn, string ln);
	PersonalAccount();
};
#endif