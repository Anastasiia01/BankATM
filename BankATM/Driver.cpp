#include <iostream>
#include "Account.h"

int main()
{
	//Create base class pointer array
	Account* accounts[8];

	//Hard code or randomly create the child objects
	accounts[0] = new PersonalSavings();
	accounts[1] = new BusinessForeignCurr();
	accounts[2] = new BusinessSavings();
	accounts[3] = new PersonalChecking();
	accounts[4] = new PersonalCD();
	accounts[5] = new BusinessHighVolChecking();
	accounts[6] = new BusinessBusinessChecking();
	accounts[7] = new PersonalMoneyMarket();

	//display the type and id by calling a polymorphic method display
	for (int i = 0; i < 8; i++)
	{
		accounts[i]->display();
	}

	return 0;
}