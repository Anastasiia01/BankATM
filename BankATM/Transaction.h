#include <iostream>
#include <string>

using namespace std;


class Transaction {
private:
	string id;
	string transactionType;// can be Deposit, Transfer, Withdraw
	//enum type { Deposit, Transfer, Withdraw } transactionType;//Deposit=0, Transfer=1, Withdraw=2

	//double amount;
	//timestamp??
public:
	Transaction(string id, string type="Deposit");//Withdraw by default
};
