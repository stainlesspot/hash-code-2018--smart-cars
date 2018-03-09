#ifndef HASH_CODE_2018_POINT_H
#define HASH_CODE_2018_POINT_H

struct Point {
	short x;
	short y;

	short distanceTo(const Point&) const;

	Point ();
	Point (short x, short y);
};

#endif //HASH_CODE_2018_POINT_H
