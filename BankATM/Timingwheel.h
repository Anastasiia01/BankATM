#ifndef TIMINGWHEEL_h
#define TIMINGWHEEL_h
#include "Partition.h"

using namespace std;
//Timingwheel is an algorithm of O(1) complexity
class Timingwheel //add destructor, =, copyconstructor
{
private:
	int size; //total number of slots in the Timingwheel
	Partition* slots; 
	int current_slot;
public:
	Timingwheel(int maxDelay = 1);
	//~Timingwheel() { delete slots; }
	//Timingwheel(const Timingwheel& copy);
	//Timingwheel& operator=(const Timingwheel& p);
	void insert(ATM* p1, int simulationTime);
	void schedule(int simulationTime);
	void clear_current_slot(); //clears partition pointer and sets to null
	friend ostream& operator<<(ostream&, Timingwheel&);
};

#endif
