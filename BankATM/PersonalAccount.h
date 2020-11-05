#include <iostream>
#include <string>
#include "Account.h"

class PersonalAccount: public Account {
private:
	string firstName;
	string lastName;
	long SSN; //9 digit 
public:
	PersonalAccount(string fn, string ln);
};
