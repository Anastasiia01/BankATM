#include "Bank.h"
#include "Customer.h"
#include "ATM.h"

#ifndef PARTITION_h
#define PARTITION_h

class Partition 
{
	private:
		//Customer* PartCostumer; //added it here so we specify who is the customer of each partition
		//Bank* atmp;
		ATM* atm;
		Partition* nextp; 
	
	public:
		
	// all needed accessor functions
		//Customer& getCustomerPtr();
		//void setCustomerPtr(Customer* customerptr);
		//Bank& getAtmPtr();
		//void setAtmPtr(Bank* atmptr);
		Partition& getNextPtr();
		void setNextPtr(Partition* nextptr);

};

#endif