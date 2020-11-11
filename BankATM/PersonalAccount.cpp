#include "PersonalAccount.h"

PersonalAccount::PersonalAccount(string fn, string ln)//implicitly calls Account()
{
	personalID = lastpersonalID; // starts assigning IDs from 1 and goes up using static count currentID
	lastpersonalID++;
	firstName = fn;
	lastName = ln;
	SSN = generateSSN();
}


int PersonalAccount::generateSSN() {
	//TODO: implement random generation of SSN 
	return 123456789;
}