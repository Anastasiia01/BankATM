#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>

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
	bool Transfer(double amount, BusinessAccount* receiverAccount); //Does the transfer happen only from business account to business account?
	bool Withdraw(double amount);
	bool ApplyInterest();

};