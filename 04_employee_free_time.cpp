/* Challenge 3, Hard
Problem Statement
For ¡®K¡¯ employees, we are given a list of intervals representing the working hours of each employee.
Our goal is to find out if there is a free interval that is common to all employees.
You can assume that each list of employee working hours is sorted on the start time.
Example 1:
Input: Employee Working Hours=[[[1,3], [5,6]], [[2,3], [6,8]]]
Output: [3,5]
Explanation: Both the employess are free between [3,5].
Example 2:
Input: Employee Working Hours=[[[1,3], [9,12]], [[2,4]], [[6,8]]]
Output: [4,6], [8,9]
Explanation: All employess are free between [4,6] and [8,9].
Example 3:
Input: Employee Working Hours=[[[1,3]], [[2,4]], [[3,5], [7,9]]]
Output: [5,7]
Explanation: All employess are free between [5,7].
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern04_merge_intervals.hpp"
#include "Interval.hpp"
using namespace std;


static vector<Interval> solver(vector<vector<Interval>> schedule) {
	vector<Interval> res;
	vector<Interval> mixup;
	for (int i = 0; i < schedule.size(); ++i) {
		for (int j = 0; j < schedule[i].size(); ++j) {
			mixup.push_back(schedule[i][j]);
		}
	}
	sort(mixup.begin(), mixup.end(), compare_interval);

	for (int i = 1; i < mixup.size(); ++i) {
		if (mixup[i].start > mixup[i - 1].end) {
			res.push_back({mixup[i-1].end, mixup[i].start});
		}
	}
	
	return res;
}

void employee_free_time() {
	vector<vector<Interval>> input{ {{ 1,3 },{ 2,4 }},{{ 3,5 },{ 7,9 }} };
	vector<Interval> ans = solver(input);

	cout << "{ ";
	for (vector<Interval>::iterator iter = ans.begin(); iter != ans.end(); ++iter) {
		cout << '{' << iter->start << ',' << iter->end << '}';
	}
	cout << " }" << endl;
	system("pause");

}