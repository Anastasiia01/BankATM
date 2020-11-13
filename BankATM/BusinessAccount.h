#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include "Account.h"
#ifndef BUSINESSACCOUNT_H_
#define BUSINESSACCOUNT_H_

static int lastbusinessID = 1;

class BusinessAccount:public Account {
	
	private:
		int businessID;//will be later used to display account ID in the following format A1P1S1
		long EIN; //Employer Identification Number
		string CompanyName;
		long getEIN() { return EIN; }
	

	public:
		BusinessAccount(string company = "University of Bridgeport");
		string getCompanyName() { return CompanyName; }
};
#endif
