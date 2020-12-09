#include "Timingwheel.h"
#include <iostream>

using namespace std;

Timingwheel::Timingwheel(int maxDelay)
{
	current_slot = 0;
	size = maxDelay +1;
	slots = new Partition[size];
}


/*Timingwheel::Timingwheel(const Timingwheel& copy)
{

}

Timingwheel& Timingwheel::operator=(const Timingwheel& p)
{
	// TODO: insert return statement here
}*/

void Timingwheel::insert(int customer_service_time, ATM* p1) {
	
	Partition part1(p1);
	int index = (current_slot + customer_service_time) % size;
	cout << "Index: " << index << endl;
	Partition* current = &slots[index];
	if (current->getATM() == nullptr) {
		Partition part(p1);
		slots[index] = part;
		cout << "Empty" << endl;
	}
	else {
		cout << "Second" << endl;
		while (current->getNext() != nullptr) {
			current = (current->getNext());
		}
		current->setNext(new Partition(p1));
		cout<< "Inserted: "<< *(current->getNext()) << endl;
	}
}

void Timingwheel::schedule()
{
	//??? the statistics of the customer leaving
	//pop the first Customer from all ATM of the Partitions in the current slot
	//pick the new first and insert() into the timing wheel

}

void Timingwheel::clear_current_slot() {
	//pop the customer of the queue and start processing the new one...
	//check the Partitions in the current slot and check their ATM numbers,
	//assign new Partitions to the free ATMs and insert them into Timingwheel
	slots[current_slot] = NULL;
}

ostream& operator<<(ostream& out, Timingwheel& tw)
{
	for (int i = 0; i < tw.size; i++) {
		cout << i << " " << tw.slots[i] << endl;
	}
	return out;
}
