#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include "BA_checking.h"
using namespace std;

class HVCABusiness : public BA_checking //Modifiy according to parent class name given 
{
private:

	string transactionID;
	double transacationFee;
	double depositeAmount;
	double withdrawAmount;
	double transferAmount;

public:
	HVCABusiness();
	bool Deposit(double checkAmount);
	bool Withdraw(double amount, BA_Checking * receiverAccount);
	bool Transfer(double amount);
	//void Transaction();

};
