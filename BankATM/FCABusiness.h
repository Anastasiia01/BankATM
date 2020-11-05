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
#include <BA_checking>
using namespace std;

class FCABusiness : public BA_checking //Modifiy according to parent class name given  
{
private:

	string transactionID;
	int transWithdrawCount;
	int tranDepositeCount;
	std::map<std::string, int> mapOfCurrency = {
			{"INR",74.33},
			{"AUD",1.40},
			{"CAD",1.32},
			{"EURO",0.85},
			{"JPY",104.32},
	};
	double depositeAmount;
	double withdrawAmount;
	double transferAmount;
public:
	FCABusiness();
	bool Deposit(double checkAmount);
	bool Transfer(double amount, BA_checking* receiverAccount);
	bool Withdraw(double amount);
	//void Transaction();


};
