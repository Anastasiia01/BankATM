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

class BusinessAccount:public Account {
	//test
	private:
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
