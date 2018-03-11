#include <iostream>
#include "../headers/Ride.h"

short Ride::bonus = 0;

bool Ride::operator< (const Ride& rhs) const {
	if (timeStart == rhs.timeStart)
		return length() < rhs.length();

	return timeStart < rhs.timeStart;
}

void Ride::print () const {
	std::cout << "[" << id << "] " <<  '(' << start.x << ", " << start.y << ") (" << finish.x << ", " << finish.y << ") "
	          << timeStart << ' ' << timeFinish << " length: " << length() << " timePeriod: " << timeFinish - timeStart << std::endl;
}

Ride::Ride(const short& id, std::istream& in)
		: id(id) {
	in >> start.x >> start.y >> finish.x >> finish.y >> timeStart
	   >> timeFinish;
}

short Ride::length() const {
	return start.distanceTo(finish);
}
