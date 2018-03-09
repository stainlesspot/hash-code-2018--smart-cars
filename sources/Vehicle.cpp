#include <iostream>
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
	//TODO: optimize for bonus
	if (!canFulfil(ride))
		return -1;

	short distance = location.distanceTo(ride.start);

	return (double)(ride.length()) / (ride.length() + (timeOfEarliestAvailability + distance > ride.timeStart ? distance : ride.timeStart));
}
