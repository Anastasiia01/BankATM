#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
#include <random>
#include "SystemController.h"

using namespace std;

SystemController::SystemController(int atmNum, int maxDelay): timingWheel(Timingwheel(maxDelay))
{
	//cout << "TW: "<<endl<<timingWheel << endl;
	for (int i = 1; i <= atmNum; i++) {
		ATM temp(i);
		atms.push_back(temp);
	}
	AvSerTime=0;
	countTime=0;
	servedCust=0;
}

void SystemController::startSim(int simTime, int dynCust, vector<Customer>& base)
{
	cout<<"Starting simulation..." << endl;
	//TODO: add shuffle for customer base: READ how to shuffle a vector
	//TODO part4: use insert() for all ATM before the for loop
	//TODO part4:at every point in time call 
	int count = 0;
	servedCust = 0;
	queue<Customer> users;//ATM queues will be used instead
	int newCust;
	for (int i = 1; i <= simTime; i++) {
		//Adds new customers
		newCust = rand() % (dynCust + 1);
		for (int j = 0; j < newCust; j++) {
			Customer cust = base[count++];
			users.push(cust);//TODO: enqueue customer in ATM with shortest queue (if arrived)
		}
		//serves current user
		//cout << "Serv Time left: " << users.front().getTimeLeft()<<endl;
		users.front().decrementTimeLeft();//TODO instead of all this part, call TW.schedule()
		if (users.front().getTimeLeft() == 0) {
			countTime += users.front().getserviceTime();//total service time
			users.pop();//deque since this user is done
			servedCust++;
			cout << "Served cust # " << servedCust<< endl;

		}

		//print_status(); //print the status of the system to the screen and output file at each simulated instance.
		//TW.clear_curr_slot(); //part 3 routine
		//time_slot = (time_slot + 1) % maximum_number_of_time_slots;
	}
	AvSerTime = countTime / servedCust;

}

double SystemController::getAvSerTime() {
	return AvSerTime;
}