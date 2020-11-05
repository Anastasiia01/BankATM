#include "PersonalCD.h"

PersonalCD::PersonalCD(string fn, string ln) : PersonalAccount(fn, ln)
{
	numWithdrawalAllowed = 6;
}

bool PersonalCD::Deposit(double checkAmount)
{
	return false;
}

bool PersonalCD::Transfer(double amount, Account* receiverAccount)
{
	return false;
}

bool PersonalCD::Withdraw(double amount)
{
	return false;
}

void PersonalCD::ApplyInterest()
{
}

void PersonalCD::display()
{
	PersonalAccount::display();
	cout << "Account type is Personal Certificates of Deposits" << endl; // we can use typedef later
}
