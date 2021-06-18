/* Challenge 1, Hard
Problem Statement
Given a list of intervals representing the start and end time of ¡®N¡¯ meetings,
find the minimum number of rooms required to hold all the meetings.
Example 1:
Meetings: [[1,4], [2,5], [7,9]]
Output: 2
Explanation: Since [1,4] and [2,5] overlap, we need two rooms to hold these two meetings. [7,9] can
occur in any of the two rooms later.
Example 2:
Meetings: [[6,7], [2,4], [8,12]]
Output: 1
Explanation: None of the meetings overlap, therefore we only need one room to hold all meetings.
Example 3:
Meetings: [[1,4], [2,3], [3,6]]
Output:2
Explanation: Since [1,4] overlaps with the other two meetings [2,3] and [3,6], we need two rooms to
hold all the meetings.

Example 4:
Meetings: [[4,5], [2,3], [2,4], [3,5]]
Output: 2
Explanation: We will need one room for [2,3] and [3,5], and another room for [2,4] and [4,5].
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern04_merge_intervals.hpp"
#include "Interval.hpp"
using namespace std;

bool _Comp(Interval a, Interval b) {
	return a.end > b.end;
}

static int solver(vector<Interval> intv) {
	sort(intv.begin(), intv.end(), compare_interval);
	vector<Interval> meetings;
	int min_room = 0;
	for(int i=0;i<intv.size();++i){
		while (!meetings.empty() && meetings[0].end <= intv[i].start) { // pop meetings that have finished
			pop_heap(meetings.begin(),meetings.end(),_Comp);
			meetings.pop_back();
		}
		meetings.push_back(intv[i]);
		push_heap(meetings.begin(),meetings.end(),_Comp);

		min_room = max(min_room, (int)meetings.size());
	}

	return min_room;
}

void minimum_meeting_rooms() {
	vector<Interval> input{ { 4,5 },{ 2,3 },{ 2,4 },{3,5} };

	int ans = solver(input);

	cout << ans << endl;
	system("pause");

}