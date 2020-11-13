#include "HVCABusiness.h"

HVCABusiness::HVCABusiness()
{
}

HVCABusiness::HVCABusiness(string fn, string ln) : BusinessAccount(fn, ln)
{
	transacationFee = 0.04; // 4% transaction fee
}

bool HVCABusiness::Deposit(double checkAmount)
{
	double transFeeAmount = ComputeTrasactionFee(checkAmount);

	BusinessAccount::Deposit(checkAmount - transFeeAmount);

}

double HVCABusiness::ComputeTrasactionFee(double checkAmount) {
	return checkAmount * transacationFee;

}

bool HVCABusiness::Withdraw(double amount)
{
	return BusinessAccount::Withdraw(amount);
}

bool HVCABusiness::Transfer(double amount, Account* receiverAccount)
{
	return BusinessAccount::Transfer(amount, receiverAccount);
}

void HVCABusiness::ApplyInterest()
{
	BusinessAccount::ApplyInterest();
}


void HVCABusiness::display()
{
	BusinessAccount::display();
	cout << "Account type is High Volume Checking Account " << endl;
}
