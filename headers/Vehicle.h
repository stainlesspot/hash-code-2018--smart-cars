#ifndef HASH_CODE_2018_VEHICLE_H
#define HASH_CODE_2018_VEHICLE_H

#include <forward_list>
#include <list>
#include <cstdint>
#include "Point.h"
#include "Ride.h"

class Vehicle {
private:
	Point location;
	uint64_t timeOfEarliestAvailability;
	std::list<Ride> assignedRides;
	short numberOfAssignedRides;

public:
	uint64_t assignClosestPossibleRide (std::forward_list<Ride>& freeRides);

	bool canFulfil (const Ride& ride) const;

	void assign (const Ride&);

	void print () const;

	double fulfilmentCost (const Ride&);

};

#endif //HASH_CODE_2018_VEHICLE_H
