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
		//TODO: we need constructor
		Partition(ATM* _atm = nullptr);
		
	// all needed accessor functions
		//Customer& getCustomerPtr();
		//void setCustomerPtr(Customer* customerptr);
		//Bank& getAtmPtr();
		//void setAtmPtr(Bank* atmptr);
		Partition*& getNextPtr();
		void setNextPtr(Partition* nextptr);
		ATM*& getATM();
		//we won't ever need to set ATM, so no setATM

};

#endif