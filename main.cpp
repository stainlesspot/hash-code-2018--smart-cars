#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include "headers/Ride.h"
#include "headers/Vehicle.h"

void giveOrders (std::vector<Vehicle>& vehicles, std::list<Ride>& freeRides) {
	bool stillMoving = true;
	while (stillMoving && !freeRides.empty()) {
		stillMoving = false;

		for (auto &vehicle : vehicles) {
			double bestScore = 0;

			auto bestRide = freeRides.begin();


			for (auto currentRide = freeRides.begin(); currentRide != freeRides.end(); ++currentRide) {
				double newScore = vehicle.fulfilmentCost(*currentRide);

				if (bestScore < newScore) {
					bestScore = newScore;
					bestRide = currentRide;

					stillMoving = true;
				}
			}
			if (bestRide != freeRides.end()) {
				vehicle.assign(*bestRide);
				freeRides.erase(bestRide);
			}
		}
	}
}


int main() {
	short rows;             // between 1 and 10 000
	short columns;          // between 1 and 10 000
	short numberOfVehicles; // between 1 and 1 000
	short numberOfRides;    // between 1 and 10 000
	short bonus;            // between 1 and 10 000
	uint64_t numberOfSteps; // between 1 and 1 000 000 000

	//std::ifstream reader("input/a_example.in");


	std::cin >> rows >> columns >> numberOfVehicles >>  numberOfRides >> bonus >> numberOfSteps;

	std::list<Ride> freeRides;

	for (short i = 0; i < numberOfRides; ++i) {
		freeRides.emplace_back(i, std::cin);
	}

//	reader.close();

	//freeRides.sort();



	std::vector<Vehicle> vehicles(numberOfVehicles);

	giveOrders(vehicles, freeRides);

	for (const auto& v : vehicles)
		v.print();


	return 0;
}