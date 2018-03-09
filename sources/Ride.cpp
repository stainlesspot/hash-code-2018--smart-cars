#include <iostream>
#include "../headers/Ride.h"


bool Ride::operator< (const Ride& rhs) const {
	if (timeStart == rhs.timeStart)
		return length() < rhs.length();

	return timeStart < rhs.timeStart;
}

Ride::Ride(const short& id, std::istream& in)
		: id(id) {
	in >> start.x >> start.y >> finish.x >> finish.y >> timeStart
	   >> timeFinish;
}

short Ride::length() const {
	return start.distanceTo(finish);
}
