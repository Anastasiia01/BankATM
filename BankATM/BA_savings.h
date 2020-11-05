#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include "Account.h"
#include "BusinessAccount.h"
#ifndef BA_SAVING_H_
#define BA_SAVING_H_
using namespace std;

class BA_savings:public BusinessAccount {

private:
	string transactionID;
	double currentBalance;
	double depositedAmount;
	double withdrawAmount;
	double transferAmount;

public:
	BA_savings();
	bool Deposit(double checkAmount);
	bool Transfer(double amount, Account * receiverAccount); //Does the transfer happen only from business account to business account?
	bool Withdraw(double amount);
	void ApplyInterest();
	void display();

};
#endif