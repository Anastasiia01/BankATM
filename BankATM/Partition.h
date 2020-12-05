#include "Bank.h"
class Partition 
{
	private:
		Customer* PartCostumer; //added it here so we specify who is the customer of each partition
		Bank* atmp;
		Partition* nextp; 
	
	public:
		
	// all needed accessor functions

		Bank& getAtmPtr();
		void setAtmPtr(Bank* atmptr);
		Partition& getNextPtr();
		void setNextPtr(Partition* nextptr);

};
