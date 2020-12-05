#include "Partition.h"

using namespace std;

class Timingwheel
{
private:
	Partition* slot[max_delay + 1];
	//max_delay (max customer transaction time possible)
	int current_slot;
public:
	
	Timingwheel();
};

