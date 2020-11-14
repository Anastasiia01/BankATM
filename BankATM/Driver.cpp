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
#include "TrafficGenerator.h"


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
	
	//Testing PersonalMoneyMarket:
	/*accounts[7]->BalanceInquiry();
	accounts[4]->BalanceInquiry();
	cout << "Interest: " <<accounts[7]->getInterest() << endl;;
	accounts[7]->Deposit(500);
	accounts[7]->Transfer(200, accounts[4]);
	accounts[4]->BalanceInquiry();
	accounts[7]->Withdraw(200);
	accounts[7]->Withdraw(200);
	accounts[7]->Withdraw(200);
	accounts[7]->Withdraw(200);

	//Testing PersonalCD:
	accounts[4]->BalanceInquiry();
	cout << "Interest: " << accounts[4]->getInterest() << endl;;
	accounts[4]->Deposit(500);
	accounts[4]->Transfer(200, accounts[7]);
	accounts[4]->BalanceInquiry();
	accounts[4]->Withdraw(200);
	accounts[4]->Withdraw(200);
	accounts[4]->Withdraw(200);
	accounts[4]->Deposit(200);
	accounts[4]->BalanceInquiry();
	accounts[4]->Withdraw(200);*/

	TrafficGenerator trafficGen;
	trafficGen.displayInfo();

	

	//display the type and id by calling a polymorphic method display
	/*for (int i = 0; i < 8; i++)
	{
		accounts[i]->display();
	}*/

	return 0;
}