#ifndef STATISTICS_H
#define STATISTICS_H

#include "SystemController.h"

class StatisticsKeeper {
private:
	int durationOfSimulation, NoATMS, NoCostumers;
public:
	StatisticsKeeper();
	void report(SystemController obj, int dur, int atmNum);
};

#endif