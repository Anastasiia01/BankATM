#include "Timingwheel.h"
#include "Bank.h"
#include <iostream>

using namespace std;

Timingwheel::Timingwheel(int _maxDelay)
{
	current_slot = 0;
	size = _maxDelay +1;
	slots = new Partition[size];

	/*for (int i = 0; i < size; i++) {
		Partition temp;
		slots[i] = temp;
		cout << i<<" "<< slots[i];
	}*/
}


void Timingwheel::insert(int customer_service_time, ATM* p1) {
	int index = (current_slot + customer_service_time) % size; //Partition is inserted in correct slot. This makes it circular
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
			//cout << "Inside while" << endl;
			current = (current->getNext());
		}
		//cout << current;
		current->setNext(new Partition(p1));
		cout<< "Inserted: "<< *(current->getNext()) << endl;
	}
}

void Timingwheel::schedule()
{
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
