/* Challenge2, Medium
Problem Statement
Given an unsorted array containing numbers, find the smallest missing positive number in it.
Example 1:
Input: [-3, 1, 5, 4, 2]
Output: 3
Explanation: The smallest missing positive number is '3'
Example 2:
Input: [3, -2, 0, 1, 2]
Output: 4
Example 3:
Input: [3, 2, 5, 1]
Output: 4
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern05_cyclic_sort.hpp"
using namespace std;

static int solver(vector<int>& nums) {
	int i = 0;
	while (i < nums.size()) {
		int j = nums[i] - 1;
		if (j >= 0 && j < nums.size() && nums[i] != nums[j]) {
			swap(nums[i], nums[j]);
		}
		else
			++i;
	}
	for (int j = 0; j < nums.size(); ++j) {
		if (nums[j] - 1 != j)
			return j + 1;
	}

	return nums.size();
}

void find_the_smallest_missing_positive_number() {
	vector<int> objs{ 3, 2, 5, 1 };
	int ans = solver(objs);


	cout << ans << endl;
	system("pause");

}