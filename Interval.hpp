#pragma once
#ifndef _INTERVAL_
#define _INTERVAL_

class Interval {
private:

public:
	int start;
	int end;

	Interval() {};
	Interval(int a, int b) : start(a), end(b) {};
};

bool isOverlap(Interval a, Interval b);
bool compare_interval(Interval a, Interval b);

#endif