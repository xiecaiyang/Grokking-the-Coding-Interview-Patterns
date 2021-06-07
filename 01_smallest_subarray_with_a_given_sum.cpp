/* Easy
Problem Statement 
Given an array of positive numbers and a positive number ¡®S¡¯, find the length of the smallest contiguous subarray whose sum is greater than or equal to ¡®S¡¯. Return 0, if no such subarray exists.
Example 1:
Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2
Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].
Example 2:
Input: [2, 1, 5, 2, 8], S=7 
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].
Example 3:
Input: [3, 4, 1, 1, 6], S=8 
Output: 3
Explanation: Smallest subarrays with a sum greater than or equal to '8' are [3, 4, 1] or [1, 1, 6].*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern_sliding_window.hpp"
using namespace std;

static int solver(vector<int>& nums, int S) {
	int left = 0, right = 0;
	int min_size = nums.size();
	int sum = 0;
	for (; right < nums.size(); right++) {
		sum += nums[right];
		while (sum >= S) {
			min_size = min(min_size, right - left + 1);
			sum -= nums[left++];		
		}
	}
	return min_size;
}

void smallest_subarray_with_a_given_sum() {
	vector<int> nums{ 3, 4, 1, 1, 6 };
	int S = 8;
	int ans = solver(nums, S);
	cout << ans << endl;
	system("pause");
}