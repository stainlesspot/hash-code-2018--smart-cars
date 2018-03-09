#ifndef HASH_CODE_2018_VEHICLE_H
#define HASH_CODE_2018_VEHICLE_H

#include <forward_list>
#include <cstdint>
#include "Point.h"
#include "Ride.h"

class Vehicle {
private:
	Point location;
	uint64_t timeOfEarliestAvailability;
	std::forward_list<Ride> assignedRides;
	short numberOfAssignedRides;

public:
	uint64_t assignClosestPossibleRide (std::forward_list<Ride>& freeRides);

	bool canFulfil (const Ride& ride);

	void assign (const Ride&);

	void print () const;

};

#endif //HASH_CODE_2018_VEHICLE_H
