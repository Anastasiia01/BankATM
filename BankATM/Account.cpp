#include "Account.h"
#include "Transaction.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include<vector>

using namespace std;

Account::Account()
{
	accountID = currentID; // starts assigning IDs from 1 and goes up using static count currentID
	currentID++;
}


bool Account::Deposit(double checkAmount)
{
	//call this deposit from the child class to reuse the code

	//Next three lines add transaction to history
	int transCount = history.size();
	Transaction trans(to_string(transCount), 0);
	history.push_back(trans);

	//do deposit
	if (checkAmount > 0) {
		balance += checkAmount;
		return true;
	}
	else {
		cout << "Invalid check amount";
		return false;
	}
}

bool Account::Transfer(double amount, Account* receiverAccount)
{
	//Next three lines add transaction to history
	int transCount = history.size();
	Transaction trans(to_string(transCount), 1);
	history.push_back(trans);

	//check if receiver exists and amount is positive
	if (receiverAccount->accountID < currentID && amount>0) {
		if (balance >= amount) { //check that balance allows to transfer such amount
			balance -= amount;
			receiverAccount->balance += amount;
			return true;
		}
		else {
			cout << "Not enough money on your balance!";
			return false;
		}
		
	}
	else {
		cout << "Invalid amount or invalid account entered";
		return false;
	}

}

bool Account::Withdraw(double amount)
{
	//Next three lines add transaction to history
	int transCount = history.size();
	Transaction trans(to_string(transCount), 2);
	history.push_back(trans);

	//do withdraw
	if (amount>0) {
		if (balance >= amount) { //check that balance allows to transfer such amount
			balance -= amount;
			return true;
		}
		else {
			cout << "Not enough money on your balance!";
			return false;
		}
	}
	else {
		cout << "Invalid amount entered";
		return false;
	}
}

void Account::ApplyInterest()
{
	//TODO: review the logic of this method
	balance += balance * interest;
}


