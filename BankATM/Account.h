
#include <vector>
#include "Transaction.h"
#ifndef ACCOUNT_H_
#define ACCOUNT_H_
static int currentID = 1;

class Account {
private:
	int accountID;
	//string password; --maybe will add later
	double balance; //by default assigned to zero
	double interest; //by default assigned to zero
	vector<Transaction> history;
protected: //methods available only to child classes
	void setInterest(double i) { interest = i; }
	void setBalance(double b) { balance = b; }
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