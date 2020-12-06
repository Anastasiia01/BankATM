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
	for (int i = 1; i <= atmNum; i++) {
		ATM temp(i);
		atms.push_back(temp);
	}
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
	systemControl.startSim(simTime, trafficGen.getDynCust(), allCustomers);
}

void Bank::get_user_input() {

}

void Bank::print_final_statistics() {

}
