/* Challenge 1, Medium
Problem Statement
Quadruple Sum to Target (medium)
Given an array of unsorted numbers and a target number, find all unique quadruplets in it, whose sum is equal to the target number.
Example 1:
Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.
Example 2:
Input: [2, 0, -1, 1, -2, 2], target=2
Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
Explanation: Both the quadruplets add up to the target.
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
//#include <string>
//#include <unordered_map>
#include "pattern02_two_pointers.hpp"
using namespace std;

static vector<vector<int>> solver(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int len = nums.size();
	vector<vector<int>> res;
	for (int i = 0; i < len - 3; i++) {
		if (i > 0 && nums[i] == nums[i - 1]) continue;

		for (int j = i + 1; j < len - 2; j++) {
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;

			int tar = target - nums[i] - nums[j];
			int left = j + 1, right = len - 1;
			while (left < right) {
				if (nums[left] + nums[right] > tar) right--;
				else if (nums[left] + nums[right] < tar) left++;
				else {
					res.push_back({nums[i], nums[j], nums[left], nums[right]});
					left++;
					right--;
					while (left < right && nums[left] == nums[left - 1]) left++;
					while (left < right && nums[right] == nums[right + 1]) right--;
				}
			}		
		}
	}

	return res;
}

void quadruple_sum_to_target() {
	vector<int> nums{ 2, 0, -1, 1, -2, 2 };
	int target = 2;
	vector<vector<int>> ans = solver(nums, target);

	for (int i = 0; i < ans.size(); i++) {
		vector<int> t = ans[i];
		cout << '{';
		for (int j = 0; j < t.size(); j++) {
			cout << t[j] << ' ';
		}
		cout << '}' << endl;
	}
	system("pause");
}