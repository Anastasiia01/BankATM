#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#ifndef STATISTICS_H
#define STATISTICS_H

class StatisticsKeeper {
private:
	int durationOfSimulation, NoATMS, NoCostumers;
public:
	StatisticsKeeper();
	double AverageSerTime();
	double AverageWaTime();
	int NoCostumersType();
	int NoTransac();
	int NoTransacType();
	double TotalDeposited();
	int numRefill();
}

#endif