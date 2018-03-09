#include "../headers/Point.h"

Point::Point ()
		: x(0), y(0) {}

Point::Point (short x, short y)
		: x(x), y(y) {}

short abs (short x) {
	return x >= 0 ? x : -x;
}

short Point::distanceTo (const Point& rhs) const {
	return abs(x - rhs.x) + abs(y - rhs.y);
}
