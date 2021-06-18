#include "Interval.hpp"

bool isOverlap(Interval a, Interval b) {
	if (a.end < b.start || b.end < a.start)
		return false;
	else
		return true;
}

bool compare_interval(Interval a, Interval b) {
	if (a.start < b.start)
		return true;
	else if (a.start == b.start) {
		return a.end < b.end;
	}
	else
		return false;
}