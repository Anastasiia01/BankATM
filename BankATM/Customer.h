#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <list>
#include "Account.h"
#include "SAPersonal.h"

using namespace std;

class Customer
{
private:
	vector <Account*> accountVec;
	int arrivalTime, serviceTime, exitTime;

public:
	Customer();
	Account* getAccount();
	void setarrivalTime();
	int getarrivalTime();
	void setserviceTime();
	int getserviceTime();
	void setexitTime();
	int getexitTime();


};