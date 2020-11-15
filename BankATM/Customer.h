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
	map <string,Account*> accountMap; //Accout Type name is used for mapping to child account object
	int arrivalTime, serviceTime, exitTime;

public:
	Customer();
	Customer(int aTime, int sTime, int eTime);
	//TODO: instead of set methods, at least arrival and service time, add as params to constructor
	void addAccount(string, Account*);
	Account* getAccount(string accountType);
	//void setarrivalTime(int aTime);
	int getarrivalTime();
	//void setserviceTime(int sTime);
	int getserviceTime();
	//void setexitTime(int eTime);
	int getexitTime();


};