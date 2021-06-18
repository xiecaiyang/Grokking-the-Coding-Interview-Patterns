/* Medium
Problem Statement
Given a list of non-overlapping intervals sorted by their start time, insert a given interval at the correct position and merge all necessary intervals to produce a list that has only mutually exclusive intervals.
Example 1:
Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,6]
Output: [[1,3], [4,7], [8,12]]
Explanation: After insertion, since [4,6] overlaps with [5,7], we merged them into one [4,7].
Example 2:
Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,10]
Output: [[1,3], [4,12]]
Explanation: After insertion, since [4,10] overlaps with [5,7] & [8,12], we merged them into [4,12].
Example 3:
Input: Intervals=[[2,3],[5,7]], New Interval=[1,4]
Output: [[1,4], [5,7]]
Explanation: After insertion, since [1,4] overlaps with [2,3], we merged them into one [1,4].
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
//#include <unordered_map>
#include "pattern04_merge_intervals.hpp"
#include "Interval.hpp"
using namespace std;

static vector<Interval> solver(vector<Interval> intv, Interval newIntv) {
	//sort(intv.begin(), intv.end(), compare_interval);
	vector<Interval> res;
	
	for (vector<Interval>::iterator iter = intv.begin(); iter != intv.end(); ++iter) {
		if (iter->end < newIntv.start || newIntv.end<iter->start) {
			res.push_back(*iter);
			continue;
		}

		int merge_start = min(iter->start, newIntv.start);
		int merge_end;
		while (iter!=intv.end()) {
			if (newIntv.end < iter->start) {
				break;
			}
			merge_end = max(iter->end, newIntv.end);
			++iter;
		}
		res.push_back(Interval{merge_start, merge_end});
		if (iter != intv.end()) res.push_back(*iter);
		else break;
		
	}
	return res;
}

void insert_interval() {
	vector<Interval> input{ { 2,3 },{ 5,7 } };
	Interval newIntv{1,4};
	vector<Interval> ans = solver(input, newIntv);

	cout << "{ ";
	for (vector<Interval>::iterator iter = ans.begin(); iter != ans.end(); ++iter) {
		cout << '{' << iter->start << ',' << iter->end << '}';
	}
	cout << " }" << endl;
	system("pause");

}