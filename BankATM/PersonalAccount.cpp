#include "PersonalAccount.h"

PersonalAccount::PersonalAccount(string fn, string ln)//implicitly calls Account()
{
	firstName = fn;
	lastName = ln;
	SSN = generateSSN();
}

int PersonalAccount::generateSSN() {
	//TODO: implement random generation of SSN 
	return 123456789;
}