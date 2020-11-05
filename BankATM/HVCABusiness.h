#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

class HVCABusiness : public CheckingAccount //Modifiy according to parent class name given 
{
private:

	string transactionID;
	double transacationFee;
	double currentBalance;
	double depositeAmount;
	double withdrawAmount;
	double transferAmount;

public:
	void Deposit();
	void Withdraw();
	void Transfer();
	//void Transaction();

};
