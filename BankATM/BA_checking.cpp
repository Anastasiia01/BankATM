#include "BA_checking.h"

BA_checking::BA_checking() {

}

bool BA_checking::Deposit(double checkAmount)
{
	return false;
}

bool BA_checking::Withdraw(double amount)
{
	return false;
}



bool BA_checking::Transfer(double amount, Account * receiverAccount)
{
	return false;
}

void BA_checking::ApplyInterest()
{

}

void BA_checking::display()
{
	BusinessAccount::display();
	cout << "Account type is Business Checking " << endl;
}