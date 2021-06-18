/* Medium
Problem Statement
Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to return the count of such triplets.
Example 1:
Input: [-1, 0, 2, 3], target=3
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]
Example 2:
Input: [-1, 4, 2, 1, 3], target=5
Output: 4
Explanation: There are four triplets whose sum is less than the target:
[-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
//#include <string>
//#include <unordered_map>
#include "pattern02_two_pointers.hpp"
using namespace std;

static int solver(vector<int>& nums, int& target) {
	sort(nums.begin(), nums.end());
	int len = nums.size();
	int sum = nums[0] + nums[1] + nums[2];
	int cnt = 0;

	for (int i = 0; i < len - 2; i++) {
		for (int j = i + 1; j < len - 1; j++) {
			int k = len - 1;
			int tar = target - nums[i] - nums[j];
			while (j < k && nums[k] >= tar) k--;
			cnt += k - j;
		}
		
	}

	return cnt;
}

void triplets_with_smaller_sum() {
	vector<int> nums{ -1, 0, 2, 3 };
	int target = 3;
	int ans = solver(nums, target);
	cout << ans << endl;

	system("pause");
}