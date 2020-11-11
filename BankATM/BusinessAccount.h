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
		int businessID;//will be later used to display account ID in the following format A1P1S1
		long EIN; //Employer Identification Number
		string CompanyName;

	protected://TODO: add constructor instead of set methods and call it from the child constructor
		void setEIN(int s) { EIN = s; }
		void setCompanyName(string nam) { CompanyName = nam; };
		

	public:
		//long getEIN() { return EIN; } it's confidential info, you don't want to make it accessible to outside world
		string getCompanyName() { return CompanyName; }
};
#endif
