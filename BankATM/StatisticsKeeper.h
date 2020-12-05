#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include "SystemController.h"
#ifndef STATISTICS_H
#define STATISTICS_H

class StatisticsKeeper {
private:
	int durationOfSimulation, NoATMS, NoCostumers;
public:
	StatisticsKeeper();
	void report(SystemController obj, int dur, int atmNum);
};

#endif