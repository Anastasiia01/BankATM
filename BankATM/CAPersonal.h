#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

class CAPersonal: public PersonalAccount //Modifiy according to parent class name given 
{
public:

	string transactionID;
	double currentBalance;
	double depositeAmount;
	double withdrawAmount;
	double transferAmount;

public:
	void Deposit();
	void Withdraw();
	void Transfer();
	//void Transaction();
};
