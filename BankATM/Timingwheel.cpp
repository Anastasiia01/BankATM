#include "Timingwheel.h"
#include "Bank.h"



Timingwheel::Timingwheel()
{
	current_slot = 0;
	for (int i = 0; i < slot.length;i++) {
		slot[i] = nullptr;
	}
}


Timingwheel::insert(int customer_service_time, ATM* p1) {
	Partition part;
	int correctSlot = 0;
	part.getCustomerPtr().setserviceTime(customer_service_time);
	correctSlot = (current_slot + 1) % slot.length; //Partition is inserted in correct slot. This makes it circular

	//if ATM is empty move to the next time slot and check for customers
	//if there is a customer waiting for the specific ATM, insert the customer 

	

}

Timingwheel::clear_current_slot() {
	Partition* slot[max_delay + 1] = 0;
}