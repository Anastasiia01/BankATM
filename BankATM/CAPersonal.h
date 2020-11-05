#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <PersonalAccount>


using namespace std;

class CAPersonal: public PersonalAccount //Modifiy according to parent class name given 
{
private:

	string transactionID;
	double depositeAmount;
	double withdrawAmount;
	double transferAmount;

public:
	CAPersonal();
	bool Deposit(double checkAmount);
	bool Transfer(double amount, PersonalAccount* receiverAccount);
	bool Withdraw(double amount);
	//void Transaction();
};
