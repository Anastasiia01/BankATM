#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include "BusinessAccount.h"

using namespace std;


class BA_checking :public BusinessAccount {
	private:
		string transactionID;
		double currentBalance;
		double depositedAmount;
		double withdrawAmount;
		double transferAmount;

	public:
		BA_checking();
		bool Deposit(double checkAmount); //deposit check
		bool Transfer(double amount, Account* receiverAccount);
		bool Withdraw(double amount);
		void ApplyInterest();
		void display();
};