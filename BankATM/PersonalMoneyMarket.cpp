#include "PersonalMoneyMarket.h"

PersonalMoneyMarket::PersonalMoneyMarket(string fn, string ln): PersonalAccount(fn, ln)
{
	numWithdrawalAllowed = 6;
	minBAlanceForInterest = 1000;
}

bool PersonalMoneyMarket::Deposit(double checkAmount)
{
	return false;
}

bool PersonalMoneyMarket::Transfer(double amount, Account* receiverAccount)
{
	return false;
}

bool PersonalMoneyMarket::Withdraw(double amount)
{
	return false;
}

void PersonalMoneyMarket::ApplyInterest()
{
}

void PersonalMoneyMarket::display()
{
	PersonalAccount::display();
	cout << "Account type is Personal Money Market" << endl; // we can use typedef later
}
