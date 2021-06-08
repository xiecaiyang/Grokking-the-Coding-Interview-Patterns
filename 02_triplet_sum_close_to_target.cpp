/* Medium
Problem Statement
Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible, return the sum of the triplet.
If there are more than one such triplet, return the sum of the triplet with the smallest sum.
Example 1:
Input: [-2, 0, 1, 2], target=2
Output: 1
Explanation: The triplet [-2, 1, 2] has the closest sum to the target.
Example 2:
Input: [-3, -1, 1, 2], target=1
Output: 0
Explanation: The triplet [-3, 1, 2] has the closest sum to the target.
Example 3:
Input: [1, 0, 1, 1], target=100
Output: 3
Explanation: The triplet [1, 1, 1] has the closest sum to the target.
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
//#include <string>
//#include <unordered_map>
#include "pattern_two_pointers.hpp"
using namespace std;

static int solver(vector<int>& nums, int& target) {
	sort(nums.begin(), nums.end());
	int len = nums.size();
	int best = nums[0] + nums[1] + nums[2];

	for (int i = 0; i < len - 2; i++) {
		int j = i + 1, k = len - 1;
		
		while (j < k) {
			int sum = nums[i] + nums[j] + nums[k];
			if (abs(sum - target) < abs(best - target)) best = sum;
			if (sum > target) k--;
			else if (sum < target) j++;
			else return sum;
		}
	}

	return best;
}

void triplet_sum_close_to_target() {
	vector<int> nums{ 1, 0, 1, 1 };
	int target = 100;
	int ans = solver(nums, target);
	cout << ans << endl;

	system("pause");
}