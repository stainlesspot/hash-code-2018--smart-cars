#ifndef HASH_CODE_2018_RIDE_H
#define HASH_CODE_2018_RIDE_H

#include <istream>
#include "Point.h"

class Ride {
	friend class Vehicle;

private:
	short id;

	Point start;
	Point finish;

	uint64_t timeStart;
	uint64_t timeFinish;

public:
	void print () const;

	bool operator< (const Ride& rhs) const;

	short length () const;

	Ride () = default;
	Ride (const short& id, std::istream&);
	~Ride () = default;
};


#endif //HASH_CODE_2018_RIDE_H
