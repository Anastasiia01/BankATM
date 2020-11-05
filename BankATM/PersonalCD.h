#pragma once
#include "PersonalAccount.h"

using namespace std;


class PersonalCD : public PersonalAccount //Modifiy according to parent class name given 
{
private:
	int numWithdrawalAllowed;
	//frozen amount/deadline
public:
	//uses default values, so constructor can be called without any parameters
	PersonalCD(string fn = "John", string ln = "Snow");
	bool Deposit(double checkAmount); //deposit check
	bool Transfer(double amount, Account* receiverAccount);
	bool Withdraw(double amount);
	void ApplyInterest();
	void display();

};
