#include "Bank.h"
class Partition 
{
	private:
		Bank* atmp;
		Partition* nextp; //maybe here it should be a vector of vectors
	
	public:
	// all needed accessor functions
		Bank* getAtmPtr();
		void setAtmPtr(Bank* atmptr);
		Partition* getNextPtr();
		void setNextPtr(Partition* nextptr);

};
