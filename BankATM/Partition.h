#ifndef PARTITION_h
#define PARTITION_h

#include "ATM.h"

class Partition //TODO: add destructor, =, copyconstructor
{
	private:
		ATM* atm;
		Partition* nextp; 	
	public:
		Partition(ATM* _atm = nullptr);
		//~Partition();
		//Partition(const Partition& copy);
		//Partition& operator=(const Partition& p);
		friend ostream& operator<<(ostream&, Partition&);
		Partition* getNext();
		void setNext(Partition* nextptr);
		ATM* getATM();
		//we won't ever need to set ATM, so no setATM
};

#endif