#include "Partition.h"

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
	void insert(int customer_service_time, ATM* p1);
	void schedule();
	Timingwheel();
};

