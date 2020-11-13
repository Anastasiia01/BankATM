#include "TrafficGenerator.h"

TrafficGenerator::TrafficGenerator(string file)
{
	transactionsToPercentile =
	{
			{40, "Deposit"},
			{80, "Withdraw"},
			{100, "Withdraw"}
	};
	//Example of inserting into the map:
	//sample_map.insert(pair<int, string>(4, "four");
	//sample.map[5] = "five";
}
