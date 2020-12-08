#ifndef ATM_h
#define ATM_h

#include <queue>
#include "Customer.h"
#include <iostream>

class ATM {
private:
	int number;
	int cashLeft;
	queue<Customer> custs;
public:
	ATM(int num = -1, int cash = 10000) { number = num; cashLeft = cash; }
	int getNum() { return number; }
	int getCashLeft() { return cashLeft; }
	void addCust(Customer cust) { custs.push(cust); }//enqueue Customer
	void delCust() { custs.pop(); }//deque Customer
	Customer* getFirst() { return &(custs.front()); }
	//refillCash()


};
#endif // !ATM_h