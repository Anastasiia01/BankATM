
#include <vector>
#include "Transaction.h"
#ifndef ACCOUNT_H_
#define ACCOUNT_H_

static int currentID = 1;

class Account {
private:
	/*A1P1S1 indicates Account # 1 Personal Account # 1 Saving (transaction) # 1
The last number indicates the transaction number associated with that type of account.
Alternatively, you can also use the format of A1P1S-1, where 1 is the transaction number and can
be stored as a separate variable.*/

	int accountID;

	double balance; //by default assigned to zero
	double interest; //by default assigned to zero
	vector<Transaction> history;
protected: //methods available only to child classes
	void setInterest(double i) { interest = i; }
	//void setBalance(double b) { balance = b; } ???
public:
	Account();
	double getInterest() { return interest; }
	//virtual bool Deposit(int bills[]) = 0; //deposit cash bills
	virtual bool Deposit(double checkAmount) = 0 ; //deposit check
	virtual bool Transfer(double amount, Account* receiverAccount) = 0;
	virtual bool Withdraw(double amount) = 0;
	virtual void ApplyInterest() = 0;
	virtual void display() = 0;
	double BalanceInquiry() { return balance; }

};
#endif