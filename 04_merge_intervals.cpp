/* Medium
Problem Statement
Example 1:
Intervals: [[1,4], [2,5], [7,9]]
Output: [[1,5], [7,9]]
Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged them into one [1,5].
Example 2:
Intervals: [[6,7], [2,4], [5,9]]
Output: [[2,4], [5,9]]
Explanation: Since the intervals [6,7] and [5,9] overlap, we merged them into one [5,9].

Example 3:
Intervals: [[1,4], [2,6], [3,5]]
Output: [[1,6]]
Explanation: Since all the given intervals overlap, we merged them into one.
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
//#include <unordered_map>
#include "pattern04_merge_intervals.hpp"
#include "Interval.hpp"
using namespace std;



static vector<Interval> solver(vector<Interval> intv) {
	sort(intv.begin(), intv.end(), compare_interval);
	vector<Interval> res;
	res.push_back(intv[0]);
	for (vector<Interval>::iterator iter = intv.begin() + 1; iter != intv.end(); ++iter) {
		Interval pre = res.back();
		Interval cur = *iter;
		if (cur.start > pre.end) {
			res.push_back(cur);
			continue;
		}
		res.pop_back();
		pre.end = max(pre.end,cur.end);
		res.push_back(pre);
	}
	return res;
}

void merge_intervals() {
	vector<Interval> input{ {1,4}, {2,5}, {7,9} };
	vector<Interval> ans = solver(input);

	cout << "{ ";
	for (vector<Interval>::iterator iter = ans.begin(); iter != ans.end(); ++iter) {
		cout << '{' << iter->start << ',' << iter->end << '}';
	}
	cout << " }" << endl;
	system("pause");

}