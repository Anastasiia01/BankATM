#include "Partition.h"
#ifndef TIMINGWHEEL_h
#define TIMINGWHEEL_h

using namespace std;
//Timingwheel is an algorithm of O(1) complexity
class Timingwheel
{
private:
	int size; //maxDelay (max customer transaction time possible)
	Partition* slots; //vector<Partition> slots;
	//somewhere here there should be a vector of vectors for the queue of partition in each slot
	int current_slot;
public:
	Timingwheel(int maxDelay);
	~Timingwheel() { delete slots; }
	void insert(int customer_service_time, ATM* p1);
	void schedule();
	void clear_current_slot(); //clears partition pointer and sets to null
	friend ostream& operator<<(ostream&, Timingwheel&);
};

#endif
