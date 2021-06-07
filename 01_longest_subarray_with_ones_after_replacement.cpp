/* Hard
Problem Statement
Given an array containing 0s and 1s, if you are allowed to replace no more than ¡®k¡¯ 0s with 1s, find the length of the longest contiguous subarray having all 1s.
Example 1:
Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
Output: 6
Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.
Example 2:
Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
Output: 9
Explanation: Replace the '0' at index 6, 9, and 10 to have the longest contiguous subarray of 1s having length 9.*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map>
#include "pattern_sliding_window.hpp"
using namespace std;

static int solver(vector<int>& nums, int k) {
	int left = 0, right = 0;
	int one_cnt = 0;
	for (; right < nums.size(); right++) {
		if (nums[right]) one_cnt++;
		if ( one_cnt + k < right - left + 1) {
			if (nums[left]) one_cnt--;
			left++;
		}
	}
	return right - left;
}

void longest_subarray_with_ones_after_replacement() {
	vector<int> nums = { 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1 };
	int k = 3;
	int ans = solver(nums, k);
	cout << ans << endl;
	system("pause");
}