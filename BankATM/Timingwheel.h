#ifndef TIMINGWHEEL_h
#define TIMINGWHEEL_h
#include "Partition.h"

using namespace std;
//Timingwheel is an algorithm of O(1) complexity
class Timingwheel //add destructor, =, copyconstructor
{
private:
	int size; //maxDelay (max customer transaction time possible)
	Partition* slots; //vector<Partition> slots;
	//somewhere here there should be a vector of vectors for the queue of partition in each slot
	int current_slot;
public:
	Timingwheel(int maxDelay = 1);
	//~Timingwheel() { delete slots; }
	//Timingwheel(const Timingwheel& copy);
	//Timingwheel& operator=(const Timingwheel& p);
	void insert(int customer_service_time, ATM* p1);
	void schedule();
	void clear_current_slot(); //clears partition pointer and sets to null
	friend ostream& operator<<(ostream&, Timingwheel&);
};

#endif
