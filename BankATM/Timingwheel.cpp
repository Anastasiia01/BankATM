#include "Timingwheel.h"
#include <iostream>

using namespace std;

Timingwheel::Timingwheel(int maxDelay)
{
	current_slot = 0;
	size = maxDelay +1;
	slots = new Partition[size];
	/*for (int i = 0; i < size; i++) {
		slots[i] = NULL;
	}*/
}


/*Timingwheel::Timingwheel(const Timingwheel& copy) : size(copy.size), current_slot(copy.current_slot)
{
	slots = new Partition[size];
	Partition* current;
	for (int i = 0; i < copy.size; i++) {
		if (copy.slots[i].getATM() != nullptr) {
			current = &copy.slots[i];
			slots[i] = *current;

			while (current->getNext() != nullptr)
			{
				current = (current->getNext());
			}

		}

	}
}*/

/*Timingwheel& Timingwheel::operator=(const Timingwheel& p)
{

	// TODO: insert return statement here
	return *this;
}*/

void Timingwheel::insert(ATM* p1) {
	//TODO: get rid of service time
	Customer* nextCust = p1->getFirst();
	int servTime = nextCust->getserviceTime();
	cout <<"Customer #" << nextCust->getID() \
		 <<" with Service time = " << servTime \
		 <<" started using ATM #" << p1->getNum() << endl;
	Partition part(p1);
	int index = (current_slot + servTime) % size; //Partition is inserted in correct slot. This makes it circular
	std::cout << "Index: " << index << endl;
	Partition* current = &slots[index];
	if (current->getATM() == nullptr) {
		//Partition part(p1);
		slots[index] = part;
		//cout << "Empty" << endl;
		//cout << "Inserted: " << part << endl;
	}
	else {
		//cout << "Second" << endl;
		while (current->getNext() != nullptr) {
			current = (current->getNext());
		}
		current->setNext(new Partition(part));
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
	//cout << "Clearing current slot - SLOT #" << current_slot;
	slots[current_slot] = Partition();
}

ostream& operator<<(ostream& out, Timingwheel& tw)
{
	cout << endl<<"------------------TIMING WHEEL-------------------" << endl;
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
