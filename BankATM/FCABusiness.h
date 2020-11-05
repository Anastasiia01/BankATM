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
using namespace std;

class FCABusiness : public CheckingAccount //Modifiy according to parent class name given  
{
private:

	string transactionID;
	int transWithdrawCount;
	int tranDepositeCount;
	std::map<std::string, int> mapOfCurr = {
			{"INR",74.33},
			{"AUD",1.40},
			{"CAD",1.32},
			{"EURO",0.85},
			{"JPY",104.32},
	};
	double currentBalance;
	double depositeAmount;
	double withdrawAmount;
	double transferAmount;
public:
	void Deposit();
	void Withdraw();
	void Interest();
	void Transfer();
	//void Transaction();

};
