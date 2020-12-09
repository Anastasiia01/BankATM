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

void Timingwheel::insert(ATM* p1) {
	//TODO: get rid of service time
	Customer* nextCust = p1->getFirst();
	int servTime = nextCust->getserviceTime();
	cout <<"Customer #" << nextCust->getID() \
		 <<" with Service time = " << servTime \
		 <<" started using ATM #" << p1->getNum() << endl;
	Partition part1(p1);
	int index = (current_slot + servTime) % size; //Partition is inserted in correct slot. This makes it circular
	cout << "Index: " << index << endl;
	Partition* current = &slots[index];
	if (current->getATM() == nullptr) {
		Partition part(p1);
		slots[index] = part;
		//cout << "Empty" << endl;
		//cout << "Inserted: " << part << endl;
	}
	else {
		//cout << "Second" << endl;
		while (current->getNext() != nullptr) {
			current = (current->getNext());
		}
		current->setNext(new Partition(p1));
		//cout<< "Inserted: "<< *(current->getNext()) << endl;
	}
}

void Timingwheel::schedule(int simulationTime)
{
	current_slot = (current_slot + 1) % size;
	Partition* current = &slots[current_slot];
	Customer* servedCust;
	Customer* nextCust;
	ATM* curATM;
	//cout << "Current Slot: " << current_slot << endl;
	if (current->getATM() != nullptr) 
	{
		while (current != nullptr) 
		{
			curATM = current->getATM();
			//Removed Served customers
			servedCust = curATM->getFirst();
			servedCust->setexitTime(simulationTime);
			cout << "Customer #" << servedCust->getID() << " left ATM #" << curATM->getNum() << endl;
			/*TODO: Gabriel use servedCust to get all needed stats here
			store in class variables and create get methods to access them
			from StatisticsKeeper()
			servedCust has proper arrived and end time that u can use*/

			curATM->delCust();//removing servedCust
			//Add new customers to be served to the free ATM Partition:
			insert(curATM);
			current = (current->getNext());
		}
	}
}

void Timingwheel::clear_current_slot() {
	//TODO:
	//pop the customer of the queue and start processing the new one...
	//check the Partitions in the current slot and check their ATM numbers,
	//assign new Partitions to the free ATMs and insert them into Timingwheel
	slots[current_slot] = NULL;
}

ostream& operator<<(ostream& out, Timingwheel& tw)
{
	cout << endl<<"------------------TIMING WHEEL------------------- " << endl;
	for (int i = 0; i < tw.size; i++) {
		if (i == tw.current_slot) {
			cout << "CURRENT SLOT -> ";
		}
		else {
			cout << "                ";
		}
		cout << i << " " << tw.slots[i] << endl;
	}
	return out;
}
