/* Medium
Problem Statement
Given two lists of intervals, find the intersection of these two lists. Each list consists of disjoint intervals sorted on their start time.
Example 1:
Input: arr1=[[1, 3], [5, 6], [7, 9]], arr2=[[2, 3], [5, 7]]
Output: [2, 3], [5, 6], [7, 7]
Explanation: The output list contains the common intervals between the two lists.
Example 2:
Input: arr1=[[1, 3], [5, 7], [9, 12]], arr2=[[5, 10]]
Output: [5, 7], [9, 10]
Explanation: The output list contains the common intervals between the two lists.
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern04_merge_intervals.hpp"
#include "Interval.hpp"
using namespace std;

static vector<Interval> solver(vector<Interval> intvA, vector<Interval> intvB) {
	vector<Interval> res;

	int i = 0, j = 0;
	while (i < intvA.size() && j < intvB.size()) {
		if (intvA[i].end < intvB[j].start) ++i;
		else if (intvA[i].start > intvB[j].end) ++j;
		else {
			int intsec_start = max(intvA[i].start, intvB[j].start);
			int intsec_end = min(intvA[i].end, intvB[j].end);
			res.push_back(Interval{intsec_start, intsec_end});
			if (intvA[i].end == intsec_end) ++i;
			if (intvB[j].end == intsec_end) ++j;
		}
	}
	
	return res;
}

void intervals_intersection() {
	vector<Interval> inputA{ { 1,3 },{ 5,7 },{ 9,12 } };
	vector<Interval> inputB{ { 5,10 } };

	vector<Interval> ans = solver(inputA, inputB);

	cout << "{ ";
	for (vector<Interval>::iterator iter = ans.begin(); iter != ans.end(); ++iter) {
		cout << '{' << iter->start << ',' << iter->end << '}';
	}
	cout << " }" << endl;
	system("pause");

}