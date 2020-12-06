#include "Timingwheel.h"
#include "Bank.h"


Timingwheel::Timingwheel(int _maxDelay)
{
	maxDelay = _maxDelay;
	slots = new Partition[maxDelay + 1];
	current_slot = 0;
	for (int i = 0; i < slots.length;i++) {
		slots[i] = nullptr;
	}
}


void Timingwheel::insert(int customer_service_time, ATM* p1) {
	Partition part;
	int correctSlot = 0;
	//part.getCustomerPtr().setserviceTime(customer_service_time);
	correctSlot = (current_slot + 1) % slots.length; //Partition is inserted in correct slot. This makes it circular

	//if ATM is empty move to the next time slot and check for customers
	//if there is a customer waiting for the specific ATM, insert the customer 

	

}

void Timingwheel::clear_current_slot() {
	slots = nullptr;
}