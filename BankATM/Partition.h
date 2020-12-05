#include "Bank.h"
class Partition 
{
	private:
		Bank* atmp;
		Partition* nextp;
	
	public:
	// all needed accessor functions
		Bank* getAtmPtr();
		void setAtmPtr(Bank* atmptr);
		Partition* getNextPtr();
		void setNextPtr(Partition* nextptr);

};
