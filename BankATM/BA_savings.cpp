#include "BA_savings.h"

BA_savings::BA_savings() {

}

bool BA_savings::Deposit(double checkAmount) {
	return false;
}


bool BA_savings::Transfer(double amount, Account * receiverAccount) {
	return false;
}


bool BA_savings::Withdraw(double amount) {
	return false;
}

void BA_savings::ApplyInterest() {
	
}

void BA_savings::display()
{
	cout << "Account type is Business Saving " << endl;
}
