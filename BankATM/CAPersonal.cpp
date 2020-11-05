#include "CAPersonal.h"

CAPersonal::CAPersonal()
{
}

bool CAPersonal::Deposit(double checkAmount)
{
	return false;
}

bool CAPersonal::Transfer(double amount, Account* receiverAccount)
{
	return false;
}

bool CAPersonal::Withdraw(double amount)
{
	return false;
}

void CAPersonal::ApplyInterest()
{
}

void CAPersonal::display()
{
	PersonalAccount::display();
	cout << "Account type is Personal Checking Account " << endl;
}
