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
	//test
	private:
		int businessID;//used to display account ID in the folllowing format A1P1S1
		long EIN; //Employer Identification Number
		string CompanyName;

	protected:
		void setEIN(int s) { EIN = s; }
		void setCompanyName(string nam) { CompanyName = nam; };
		

	public:
		long getEIN() { return EIN; }
		string getCompanyName() { return CompanyName; }
};
#endif
