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
	//if ATM is empty, [check for customers waiting in other ATMs and insert], move to the next time slot and check for customers
	//if there is a customer waiting for the specific ATM, insert the customer 

}
