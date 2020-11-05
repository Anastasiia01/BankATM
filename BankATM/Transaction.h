#include <iostream>
#include <string>

using namespace std;


class Transaction {
private:
	string id;
	enum type { Deposit, Transfer, Withdraw } transactionType;//Deposit=0, Transfer=1, Withdraw=2
public:
	Transaction(string id, int transactionType = 2);//Withdraw by default
};
