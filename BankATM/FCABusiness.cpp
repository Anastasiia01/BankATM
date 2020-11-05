#include "FCABusiness.h"

FCABusiness::FCABusiness()
{
}

bool FCABusiness::Deposit(double checkAmount)
{
	return false;
}

bool FCABusiness::Transfer(double amount, Account* receiverAccount)
{
	return false;
}

bool FCABusiness::Withdraw(double amount)
{
	return false;
}

void FCABusiness::ApplyInterest()
{
}

void FCABusiness::display()
{
	cout << "Account type is Foreign Currency Account " << endl;
}

