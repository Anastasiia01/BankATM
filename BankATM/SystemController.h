#ifndef	SYSTEMCONTROLLER_h
#define SYSTEMCONTROLLER_h
#include "ATM.h"
#include "Timingwheel.h"

class SystemController {
private:
	vector<ATM> atms;
	Timingwheel timingWheel;
	double AvSerTime;
	double countTime;
	int servedCust;

public:
	SystemController(int atmNum =-1, int maxDelay=-1);
	void startSim(int simTime, int dynCust, vector<Customer>& base);
	double getAvSerTime();
	int getServed() { return servedCust; }

};
#endif