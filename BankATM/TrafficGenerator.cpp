#include <iostream>
#include <string>
#include <tuple>
#include <queue>
#include <fstream>
#include <iterator>

#include "TrafficGenerator.h"
#include "Account.h"

#include "BA_savings.h"
#include "BA_checking.h"
#include "FCABusiness.h"
#include "HVCABusiness.h"

#include "CAPersonal.h"
#include "PersonalMoneyMarket.h"
#include "SAPersonal.h"
#include "PersonalCD.h"


TrafficGenerator::TrafficGenerator(string file)
{
	parseFile(file);
	transactionsToPercentile =
	{
			{40, "Deposit"},
			{80, "Withdraw"},
			{100, "Tranfer"}
	};

}

void TrafficGenerator::parseFile(string file)
{
	ifstream input(file);
	input >> customerBase;
	input >> initCustomersNum;
	input >> dynCustomersNum;
	int val1, val2;
	input >> val1 >> val2;
	serviceTimeRange = make_tuple(val1, val2);
	input >> multAccountPercentile;
	string typeName;
	input >> typeName;
	if (typeName == "Personal") {
		input >> persAccountPercentile;
	}
	input >> typeName >> typeName;//ignore Business line
	//val1 = val2 = 0;
	int pSum = 0;
	int bSum = 0;
	while (input.good())
	{
		input >> typeName;
		input >> val1 >> val2;
		if (val1 != 0)
		{
			pertypesToPercentile.insert(pair<int, string>(val1 + pSum, typeName));
			//pertypesToPercentile[val1 + pSum] = typeName;
		}
		if (val2 != 0)
		{
			bustypesToPercentile.insert(pair<int, string>(val2 + bSum, typeName));
		}
		pSum += val1;
		bSum += val2;
	}

	input.close();
}

void TrafficGenerator::displayInfo()
{
	cout << "Customer Base: " << customerBase << endl;
	cout << "Initial Customer Number: " << initCustomersNum << endl;
	cout << "Dynamic Customer Number: " << dynCustomersNum << endl;
	cout << "Service time range is from " << get<0>(serviceTimeRange)<<" to "<< get<1>(serviceTimeRange)<< endl;
	cout << "Percentage of users with multiple accounts: " << multAccountPercentile << "%"<< endl;
	cout << "Percentage of personal accounts: " << persAccountPercentile << "%"<< endl;
	cout << "Personal account percentiles: " << endl;
	map<int, string>::iterator iter;
	for (iter = pertypesToPercentile.begin(); iter != pertypesToPercentile.end(); ++iter)
	{
		cout << (*iter).first << ": " << (*iter).second << endl;
	}
	cout << "Business account percentiles: " << endl;
	for (iter = bustypesToPercentile.begin(); iter != bustypesToPercentile.end(); ++iter)
	{
		cout << (*iter).first << ": " << (*iter).second << endl;
	}
}

queue<Customer>& TrafficGenerator::getInitTraffic()
{
	/* Use statistical values that were read from the file to generate inital Customer queue*/
	int serviceTime, multAccountcheck, numOfAccounts;
	int PorB, accountType;
	string accType;
	int range = get<1>(serviceTimeRange) - get<0>(serviceTimeRange)+1;
	cout << "Range of serv time: "<<range<<endl;
	Account* accoutnPt = new SAPersonal();
	//Customer* cust1;
	//cout << c.getserviceTime();
	for (int i = 0; i < initCustomersNum; i++)
	{
		cout << "Customer# " << i << endl;
		cout << "********************************************************" << endl;
		//generates one Customer at a time
		serviceTime = rand() % range + get<0>(serviceTimeRange);
		cout << "Serv time: " << serviceTime << endl;
		Customer cust(0, serviceTime, 0);
		multAccountcheck = rand() % 101;
		cout << "multAccountcheck: " << multAccountcheck << endl;
		if (multAccountcheck > multAccountPercentile)// one account
		{
			numOfAccounts = 1; 
		}
		else {//multiple accounts
			numOfAccounts = rand() % 3+2;//2-4 accounts
		}
		cout << "Number of Accounts: " << numOfAccounts << endl;
		for (int j = 0; j < numOfAccounts; j++)
		{
			//generates one Account at a time
			PorB = rand() % 101;
			accountType = rand() % 101;
			cout << "j: "<<j<<endl;
			//cout << "PerOrBus: " << PorB << endl;
			//cout << "accountType: " << accountType << endl;
			if (PorB > persAccountPercentile)// business account
			{
				for (auto const& x : bustypesToPercentile)
				{
					cout << "Key: " << x.first << endl;
					if (accountType < x.first) // string (key)
					{
						//x.second
						accType = x.second;
						if (accType == "Savings")
						{
							accoutnPt = new BA_savings();
							accType = "BSA";//abbreviation used to add accounts into Customer class
						}
						else if (accType == "Checking")
						{
							accoutnPt = new BA_checking();
							accType = "BCA";
						}
						else if (accType == "HighVolumeChecking")
						{
							accoutnPt = new HVCABusiness();
							accType = "BHVC";
						}
						else //ForeignCurrency
						{
							accoutnPt = new FCABusiness();
							accType = "BFC";
						}
						break;
					}//end inner if
				}//end for
			}//end outer if
			else {//personal account
				for (auto const& x : pertypesToPercentile)
				{
					//cout << "Key: " << x.first << endl;
					if (accountType < x.first) // string (key)
					{
						//x.second
						accType = x.second;
						if (accType == "Savings")
						{
							accoutnPt = new SAPersonal();
							accType = "PSA";//abbreviation used to add accounts into Customer class
						}
						else if (accType == "Checking")
						{
							accoutnPt = new CAPersonal();
							accType = "PCA";
						}
						else if (accType == "MoneyMarket")
						{
							accoutnPt = new PersonalMoneyMarket();
							accType = "PMM";
						}
						else //CertificateOfDeposits
						{
							accoutnPt = new PersonalCD();
							accType = "PCD";
						}
						break;
					}//end inner if
				}//end for
			}//end else
			//Account* pt = cust.getAccount(accType);

			cust.displayAccounts();
			cout << "Account type I want to add: "<< accType << endl;
			if (cust.getAccount(accType)==nullptr) 
			{
				cout << "Adding" << endl;
				cust.addAccount(accType, accoutnPt);
			}
			else {
				cout << "Repetative!" << endl;
				numOfAccounts++;//skip this account as it is repeatative and create one more
			}
		}//end for that create one account per iteration
		
		initCustomers.push(cust);
	}

	cout << "Init Customer num: " << initCustomers.size() << endl;
	
	return initCustomers;
}
