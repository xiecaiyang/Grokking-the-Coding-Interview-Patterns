/* Medium
Problem Statement
Given an array of intervals representing ¡®N¡¯ appointments, find out if a person can attend all the appointments.

Example 1:

Appointments: [[1,4], [2,5], [7,9]]
Output: false
Explanation: Since [1,4] and [2,5] overlap, a person cannot attend both of these appointments.

Example 2:

Appointments: [[6,7], [2,4], [8,12]]
Output: true
Explanation: None of the appointments overlap, therefore a person can attend all of them.

Example 3:

Appointments: [[4,5], [2,3], [3,6]]
Output: false
Explanation: Since [4,5] and [3,6] overlap, a person cannot attend both of these appointments.
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern04_merge_intervals.hpp"
#include "Interval.hpp"
using namespace std;

static bool solver(vector<Interval> intv) {
	sort(intv.begin(), intv.end(), compare_interval);
	for (int i = 1; i < intv.size();++i) {
		if (intv[i - 1].end > intv[i].start) return false;
	}

	return true;
}

void conflicting_appointments() {
	vector<Interval> input{ { 4,5 },{ 2,3 },{ 3,6 } };

	bool ans = solver(input);

	cout << ans << endl;
	system("pause");

}