#include "SAPersonal.h"

SAPersonal::SAPersonal()
{
}

bool SAPersonal::Deposit(double checkAmount)
{
	return false;
}

bool SAPersonal::Transfer(double amount, Account* receiverAccount)
{
	return false;
}

bool SAPersonal::Withdraw(double amount)
{
	return false;
}

void SAPersonal::ApplyInterest()
{
	
}

void SAPersonal::display()
{
	cout << "Account type is Personal Saving Account " << endl;
}
