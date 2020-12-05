#include<queue>
#include<vector>
#include "SystemController.h"

void SystemController::startSim(int simTime, int dynCust, vector<Customer>& base)
{
	//TODO: add shuffle for customer base
	int count = 0;
	servedCust = 0;
	queue<Customer> users;
	int newCust;
	for (int i = 1; i <= simTime; i++) {
		//Adds new customers
		newCust = rand() % (dynCust + 1);
		for (int j = 0; j < newCust; j++) {
			Customer cust = base[count++];
			users.push(cust);
		}
		//serves current user
		//cout << "Serv Time left: " << users.front().getTimeLeft()<<endl;
		users.front().decrementTimeLeft();
		if (users.front().getTimeLeft() == 0) {
			countTime += users.front().getserviceTime();//total service time
			users.pop();//deque since this user is done
			servedCust++;
			cout << "Served cust # " << servedCust<< endl;

		}
	}
	AvSerTime = countTime / servedCust;

}

double SystemController::getAvSerTime() {
	return AvSerTime;
}