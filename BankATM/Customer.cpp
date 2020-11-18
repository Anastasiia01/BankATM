#include "Customer.h"

Customer::Customer()
{
	arrivalTime = 0;
	serviceTime = 0;
	exitTime = 0;
	//accountMap = { {"PSA",nullptr},{"PCA",nullptr},{"PMM",nullptr},
	//{"PCD",nullptr}, {"BSA",nullptr}, {"BCA",nullptr}, 
	//{"BHVC",nullptr}, {"BFC",nullptr} };
}

Customer::Customer(int aTime, int sTime, int eTime)
{
	arrivalTime = aTime;
	serviceTime = sTime;
	exitTime = eTime;
}

void Customer::addAccount(string accountType, Account* accountObj)
{
	cout << "Adding account....." << endl;
	cout << "Account Type: " << typeid(*accountObj).name() << endl;
	cout << "Account pointer: " << accountObj << endl;
	// Please follow this nomanclature for input string accountType
	// For Personal Savings - "PSA"
	// For Personal Checking - "PCA"
	// For Personal Money Market - "PMM"
	// For Personal Certifiation of Deposit - "PCD"
	// For Business Savings - "BSA"
	// For Business Checking - "BCA"
	// For Business High Volume Checking - "BHVC"
	// For Business Foreign Currency - "BFC"

	accountMap.insert({ accountType, accountObj });
}

Account* Customer::getAccount(string accountType)
{
	cout << "Getting account....." << endl;
	// Please follow this nomanclature for input string accountType
	// For Personal Savings - "PSA"
	// For Personal Checking - "PCA"
	// For Personal Money Market - "PMM"
	// For Personal Certifiation of Deposit - "PCD"
	// For Business Savings - "BSA"
	// For Business Checking - "BCA"
	// For Business High Volume Checking - "BHVC"
	// For Business Foreign Currency - "BFC"

	Account* accountReturn;

	//Convert accountType to Upper case
	//transform(accountType.begin(), accountType.end(), accountType.begin(), ::toupper);
	//cout << "Customer accountType" << accountType<<endl;
	accountReturn = accountMap[accountType];
	//cout << "Account Type: " << typeid(*accountReturn).name() << endl;
	if (accountReturn != nullptr)
	{
		cout << "Not null " << endl;
		return accountReturn;
	}
	else
	{
		cout << "null " << endl;
		return nullptr;
	}
}

/*
void Customer::setarrivalTime(int aTime)
{
}*/

int Customer::getarrivalTime()
{
	return arrivalTime;
}
/*
void Customer::setserviceTime(int sTime)
{
}*/

int Customer::getserviceTime()
{
	return serviceTime;
}
/*
void Customer::setexitTime(int eTime)
{
}*/

int Customer::getexitTime()
{
	return exitTime;
}


void Customer::displayAccounts()
{
	cout << "Available accounts are:" << endl;
	for (auto const& x : accountMap)
	{
		cout << "Account: " << x.first << endl;
		cout << "Pointer: "<< x.second << endl;
	}

}
