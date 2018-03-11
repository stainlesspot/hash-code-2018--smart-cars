#include <iostream>
#include <cmath>
#include "../headers/Vehicle.h"

uint64_t Vehicle::assignClosestPossibleRide (std::forward_list<Ride>& freeRides) {
	auto ride = freeRides.begin();
	auto end = freeRides.end();

	if (canFulfil(*ride)) {
		assign(*ride);
		freeRides.pop_front();
		return timeOfEarliestAvailability;
	}
	else if (ride != end)
		for (auto prev = ride; ride != end; prev = ride, ++ride)
			if (canFulfil(*ride)) {
				assign(*ride);
				freeRides.erase_after(prev);
				return timeOfEarliestAvailability;
			}
}

bool Vehicle::canFulfil (const Ride& ride) const {
	return location.distanceTo(ride.start) <= ride.timeFinish - ride.length();
}

void Vehicle::assign (const Ride& ride) {
	short distance = location.distanceTo(ride.start);
	timeOfEarliestAvailability =  (timeOfEarliestAvailability + distance > ride.timeStart ? timeOfEarliestAvailability + distance : ride.timeStart) + ride.length();
	location = ride.finish;
	assignedRides.push_back(ride);
	++numberOfAssignedRides;
}

void Vehicle::print () const {
	std::cout << numberOfAssignedRides << ' ';
	for (const auto& ride : assignedRides)
		std::cout << ride.id << ' ';

	std::cout << std::endl;
}

double Vehicle::fulfilmentCost (const Ride& ride) {
	if (!canFulfil(ride))
		return -1;

	short distance = location.distanceTo(ride.start);

	uint64_t timeBeginRide;
	short bonusPoints;

	if (timeOfEarliestAvailability + distance > ride.timeStart) {
		timeBeginRide = distance + timeOfEarliestAvailability;
		bonusPoints = 0;
	}
	else {
		timeBeginRide = ride.timeStart;
		bonusPoints = Ride::bonus;
	}
	return (double)(ride.length() + bonusPoints) / std::pow(ride.length() + timeBeginRide, 2);
}
