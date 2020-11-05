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
#ifndef SAPERSONAL_H_
#define SAPERSONAL_H_
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
	bool Transfer(double amount, Account * receiverAccount);
	bool Withdraw(double amount);
	void ApplyInterest();
	void display();
	//void Transaction();
};
#endif

