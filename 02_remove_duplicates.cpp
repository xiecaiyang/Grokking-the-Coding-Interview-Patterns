/* Easy
Problem Statement
Given an array of sorted numbers, remove all duplicates from it. You should not use any extra space; after removing the duplicates in-place return the new length of the array.
Example 1:
Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].
Example 2:
Input: [2, 2, 2, 11]
Output: 2
Explanation: The first two elements after removing the duplicates will be [2, 11].*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "pattern_two_pointers.hpp"
using namespace std;

static int solver(vector<int>& nums) {
	int i = 0, j = 0;
	for (; j < nums.size(); j++) {
		if (!j) {
			i++;
		}
		if (j>0 && nums[j] != nums[j - 1]) {
			nums[i] = nums[j];
			i++;
		}
	}

	return i;
}

void remove_duplicates() {
	vector<int> nums{ 2, 2, 2, 11 };
	int ans = solver(nums);
	cout <<ans<< endl;
	system("pause");
}