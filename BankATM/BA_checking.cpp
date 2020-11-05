#include "BA_checking.h"

BA_checking::BA_checking() {

}

bool BA_checking::Deposit(double checkAmount)
{
	return false;
}

bool BA_checking::Withdraw(double amount, BA_checking* receiverAccount)
{
	return false;
}

bool BA_checking::Transfer(double amount)
{
	return false;
}
void ApplyInterest() {

}

void display() {

	BusinessAccount::display();
	cout << "Account type is Business Checking " << endl;

}