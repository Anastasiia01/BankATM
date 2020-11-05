#include <iostream>
#include <string>
#ifndef TRANSACTION_H_
#define TRANSACTION_H_
using namespace std;


class Transaction {
private:
	string id;
	//double amount;
	//timestamp??
	enum type { Deposit, Transfer, Withdraw } transactionType;//Deposit=0, Transfer=1, Withdraw=2
public:
	Transaction(string id, int transactionType = 2);//Withdraw by default
};
#endif
