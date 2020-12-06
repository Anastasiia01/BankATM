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
	ATM(int num, int cashLeft = 10000) { number = num; }

};
#endif // !ATM_h