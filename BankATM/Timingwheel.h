#include "Partition.h"
#ifndef TIMINGWHEEL_h
#define TIMINGWHEEL_h

using namespace std;
//Timingwheel is an algorithm of O(1) complexity
class Timingwheel
{
private:
	Partition* slot[max_delay + 1];
	//max_delay (max customer transaction time possible)
	//somewhere here there should be a vector of vectors for the queue of partition in each slot
	int current_slot;
public:
	Timingwheel();
	void insert(int customer_service_time, ATM* p1);
	void schedule();
	void clear_current_slot(); //clears partition pointer and sets to null
};

#endif
