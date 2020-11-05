#include <iostream>
#include <algorithm>
#include <iterator>
#include<vector>

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
	void Deposit();
	void Withdraw();
	void Transfer();

};