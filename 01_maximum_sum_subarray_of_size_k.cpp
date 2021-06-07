/* Easy
Problem Statement #
Given an array of positive numbers and a positive number ¡®k¡¯, find the maximum sum of any contiguous subarray of size ¡®k¡¯.
Example 1:
Input: [2, 1, 5, 1, 3, 2], k = 3
Output : 9
Explanation : Subarray with maximum sum is[5, 1, 3].
Example 2 :
Input : [2, 3, 4, 1, 5], k = 2
Output : 7
Explanation : Subarray with maximum sum is[3, 4].*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern_sliding_window.hpp"
using namespace std;

static int solver(vector<int>& nums, int k) {
	int len = nums.size();
	int ans = 0;
	int max = 0;

	for (int i = 0; i + k < len + 1; i++) {
		if (i == 0) {
			for (int j = 0; j < k; j++) ans += nums[j];
		}
		else {
			ans += nums[i + k - 1] - nums[i - 1];
		}
		max = std::max(max, ans);
		
	}
	return max;
}

void maximum_sum_subarray_of_size_k() {
	vector<int> nums{ 2, 3, 4, 1, 5 };
	int k = 2;
	int ans = solver(nums, k);
	cout << ans << endl;
	system("pause");
}