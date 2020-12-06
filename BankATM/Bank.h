#include "TrafficGenerator.h"
#include "StatisticsKeeper.h"
#include "SystemController.h"
#include "ATM.h"

#ifndef BANK_h
#define BANK_h

class Bank {
private:
	TrafficGenerator trafficGen;
	StatisticsKeeper statsKeeper;
	SystemController systemControl;
	vector<Customer>allCustomers;//vector of 200 Customers
	int atmNum;
	vector<ATM> atms;
	int simTime;
	string inputFile;

public:
	//Bank();
	void set_inputfile(string file);
	void set_atm_num(int atm);
	void get_user_input(); //for part 4, get all the user specified values
	void set_sim_time(int time) { simTime = time; }
	void report();//calls statsKeeper.report()
	void generate_customerbase(); // trafficGen.initCustomersBase();
	//void generate_initial_traffic();// trafficGen.initTraffic(); TODO: add later
	void simulate();//call systemControl.startSimulation();
	void print_final_statistics(); //for part 4, prints  print the final report of the simulation
	

};
#endif