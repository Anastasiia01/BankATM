#include "TrafficGenerator.h"
#include <iostream>
#include <string>
#include <tuple>
#include <fstream>
#include <iterator>


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
