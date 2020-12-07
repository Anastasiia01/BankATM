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
	Partition part(p1);
	Partition* partPtr = &part;
	int index = (current_slot + customer_service_time) % size; //Partition is inserted in correct slot. This makes it circular
	cout << "Index: " << index << endl;
	Partition current = slots[index];//???
	cout << "Inside Insert():" << endl;
	if (current.getATM() == nullptr) {
		slots[index] = part;
		cout << "Empty" << endl;
	}
	else {
		cout << "Second" << endl;
		while (current.getNext() != nullptr) {
			//cout << "Inside while" << endl;
			current = *(current.getNext());
		}
		cout << current;
		current.setNext(partPtr);
	}
	/*TODO: while loop to get to the end of Partition linked list and assign last 
    Tartition* nextp to be "part" that we just created.*/
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
		cout << i<<" "<< tw.slots[i];
	}
	return out;
}
