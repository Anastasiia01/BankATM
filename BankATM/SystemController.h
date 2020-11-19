#ifndef	SYSTEMCONTROLLER_h
#define SYSTEMCONTROLLER_h
#include "Customer.h"

class SystemController {

private:
	double AvSerTime;
	double countTime;
	int servedCust;
public:
	void startSim(int simTime, int dynCust, vector<Customer>& base);
	double getAvSerTime();
	int getServed() { return servedCust; }

};
#endif