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

class SAPersonal: public PersonalAccount //Modifiy according to parent class name given 
{
private:

	string transactionID;
	double interestRate;
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

