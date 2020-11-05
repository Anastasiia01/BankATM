#include <iostream>
#include "Account.h"
#include "BA_checking.h"
#include"BA_savings.h"
#include"BusinessAccount.h"
#include"CAPersonal.h"
#include"FCABusiness.h"
#include "HVCABusiness.h"
#include "PersonalAccount.h"
#include "PersonalMoneyMarket.h"
#include"SAPersonal.h"
#include"Transaction.h"
#include "PersonalCD.h"


int main()
{
	//Create base class pointer array
	Account* accounts[8];

	//Hard code or randomly create the child objects
	accounts[0] = new SAPersonal();
	accounts[1] = new FCABusiness();
	accounts[2] = new BA_savings();
	accounts[3] = new CAPersonal();
	accounts[4] = new PersonalCD(); //check
	accounts[5] = new HVCABusiness();
	accounts[6] = new BA_checking();
	accounts[7] = new PersonalMoneyMarket();

	//display the type and id by calling a polymorphic method display
	for (int i = 0; i < 8; i++)
	{
		accounts[i]->display();
	}

	return 0;
}