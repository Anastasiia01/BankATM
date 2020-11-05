#include <iostream>
#include <string>
#include "Account.h"

class PersonalAccount: public Account {
private:
	string firstName;
	string lastName;
	int SSN; //9 digit 
	int generateSSN();
public:
	PersonalAccount(string fn, string ln); 
};
