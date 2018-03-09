#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include <forward_list>
#include "headers/Ride.h"
#include "headers/Vehicle.h"

int main() {
	short rows;             // between 1 and 10 000
	short columns;          // between 1 and 10 000
	short numberOfVehicles; // between 1 and 1 000
	short numberOfRides;    // between 1 and 10 000
	short bonus;            // between 1 and 10 000
	uint64_t numberOfSteps; // between 1 and 1 000 000 000

	std::ifstream reader("input/c_no_hurry.in");


	reader >> rows >> columns >> numberOfVehicles >>  numberOfRides >> bonus >> numberOfSteps;

	std::forward_list<Ride> freeRides;

	for (short i = 0; i < numberOfRides; ++i)
		freeRides.emplace_front(i, reader);

	reader.close();

	freeRides.sort();

	std::vector<Vehicle> vehicles(numberOfVehicles);

	uint64_t smallestStep = 0;

	for (auto vehicle = vehicles.begin(), end = vehicles.end(); !freeRides.empty(); ++vehicle) {

		if (vehicle == end)
			vehicle = vehicles.begin();

		uint64_t min = vehicle->assignClosestPossibleRide(freeRides);



	}


	for (const auto& v : vehicles)
		v.print();


	return 0;
}