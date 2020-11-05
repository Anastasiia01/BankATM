#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include "PersonalAccount.h"

using namespace std;

class SAPersonal: public PersonalAccount //Modifiy according to parent class name given 
{
private:

	string transactionID;
	double depositeAmount;
	double withdrawAmount;
	double transferAmount;


public:
	SAPersonal();
	bool Deposit(double checkAmount);
	bool Transfer(double amount, PersonalAccount* receiverAccount);
	bool Withdraw(double amount);
	bool ApplyInterest();
	//void Transaction();
};

