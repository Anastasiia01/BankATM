#ifndef TIMINGWHEEL_h
#define TIMINGWHEEL_h
#include "Partition.h"

using namespace std;
//Timingwheel is an algorithm of O(1) complexity
class Timingwheel //add destructor, =, copyconstructor
{
private:
	int size; //total number of slots in the Timingwheel
	Partition* slots; //dynamic array
	int current_slot;
	int averageWaitingTime;
public:
	Timingwheel(int maxDelay = 1);
	//~Timingwheel() { delete[] slots; }
	//Timingwheel(const Timingwheel& copy);
	//Timingwheel& operator=(const Timingwheel& p);
	void insert(ATM* p1);
	void schedule(int simulationTime);
	void clear_current_slot(); //clears partition pointer and sets to null
	void incrementCurrent() { current_slot = (current_slot + 1) % size; }
	friend ostream& operator<<(ostream&, Timingwheel&);
};

#endif
