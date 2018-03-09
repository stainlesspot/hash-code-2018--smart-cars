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

bool Vehicle::canFulfil (const Ride& ride) {
	return location.distanceTo(ride.start) <= ride.timeStart - timeOfEarliestAvailability;
}

void Vehicle::assign (const Ride& ride) {
	location = ride.finish;
	timeOfEarliestAvailability = ride.timeStart + ride.length();
	assignedRides.push_front(ride);
	++numberOfAssignedRides;
}

void Vehicle::print () const {
	std::cout << numberOfAssignedRides << ' ';
	for (const auto& ride : assignedRides)
		std::cout << ride.id << ' ';

	std::cout << std::endl;
}