#include "TrafficGenerator.h"
#include <iostream>
#include <string>
#include <tuple>
#include <fstream>


TrafficGenerator::TrafficGenerator(string file)
{
	ifstream input(file);
	input >> customerBase;
	input >> initCustomersNum;
	input >> dynCustomersNum;
	int start, end;
	input >> start;
	input >> end;
	serviceTimeRange = make_tuple(start, end);
	input >> multAccountPercentile;

	transactionsToPercentile =
	{
			{40, "Deposit"},
			{80, "Withdraw"},
			{100, "Tranfer"}
	};
	//Example of inserting into the map:
	//sample_map.insert(pair<int, string>(4, "four");
	//sample.map[5] = "five";

	input.close();
}

void TrafficGenerator::displayInfo()
{
	cout << "Customer Base: " << customerBase << endl;
	cout << "Initial Customer Number: " << initCustomersNum << endl;
	cout << "Dynamic Customer Number: " << dynCustomersNum << endl;

	cout << "Service time range is from " << get<0>(serviceTimeRange)<<" to "<< get<1>(serviceTimeRange)<< endl;
}
