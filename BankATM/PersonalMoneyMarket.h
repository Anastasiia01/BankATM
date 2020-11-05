#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include "Account.h"
#include "PersonalAccount.h"
#ifndef PERSONALMONEYMARKET_H_
#define PERSONALMONEYMARKET_H_

using namespace std;


class PersonalMoneyMarket : public PersonalAccount //Modifiy according to parent class name given 
{
private:
	int numWithdrawalAllowed;
	double minBAlanceForInterest;
public:
	//uses default values, so constructor can be called without any parameters
	PersonalMoneyMarket(string fn ="John", string ln ="Snow");
	bool Deposit(double checkAmount); //deposit check
	bool Transfer(double amount, Account* receiverAccount);
	bool Withdraw(double amount);
	void ApplyInterest();
	void display();

};
#endif