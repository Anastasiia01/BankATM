#include "Bank.h"

void Bank::set_inputfile(string file)
{
	inputFile = file;
	trafficGen = TrafficGenerator(inputFile);
	//trafficGen.displayInfo();
}

void Bank::set_atm_num(int atm)
{
	atmNum = atm;
	int maxTime = trafficGen.maxServiceTime(); //for debug
	systemControl = SystemController(atmNum, maxTime);
}

void Bank::report()
{
	statsKeeper.report(systemControl, simTime, atmNum);
}

void Bank::generate_customerbase()
{
	allCustomers = trafficGen.initCustomerBase();
	cout << "Generated customer base: " << allCustomers.size() << endl;
}

void Bank::simulate()
{
	systemControl.startSim2(simTime, trafficGen.getDynCust(), allCustomers);
}

void Bank::get_user_input() {
	int ATMs = 0, time = 0;
	string fname = "";
	cout << "Please specify input file name:\n";
    cin >> fname;
	set_inputfile(fname);
	cout << "Number of ATMs:\n";
	cin >> ATMs; 
	set_atm_num(ATMs);
	cout << "Simulation time:\n";
	cin >> time;
	set_sim_time(time);
}

void Bank::print_final_statistics() {

}
