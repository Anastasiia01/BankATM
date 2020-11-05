#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>

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
};