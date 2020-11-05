#include "HVCABusiness.h"

HVCABusiness::HVCABusiness()
{
}

bool HVCABusiness::Deposit(double checkAmount)
{
	return false;
}

bool HVCABusiness::Withdraw(double amount)
{
	return false;
}

bool HVCABusiness::Transfer(double amount, Account* receiverAccount)
{
	return false;
}

void HVCABusiness::ApplyInterest()
{
	
}

void HVCABusiness::display()
{
	cout << "Account type is High Volume Checking Account " << endl;
}
