#include "Bank.h"
#include "Customer.h"
#ifndef PARTITION_h
#define PARTITION_h

class Partition 
{
	private:
		Customer* PartCostumer; //added it here so we specify who is the customer of each partition
		Bank* atmp;
		Partition* nextp; 
	
	public:
		
	// all needed accessor functions
		Customer& getCustomerPtr();
		void setCustomerPtr(Customer* customerptr);
		Bank& getAtmPtr();
		void setAtmPtr(Bank* atmptr);
		Partition& getNextPtr();
		void setNextPtr(Partition* nextptr);

};

#endif