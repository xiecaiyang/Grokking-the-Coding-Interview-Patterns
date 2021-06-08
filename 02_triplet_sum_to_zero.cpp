/* Medium
Problem Statement
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.
Example 1:
Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.
Example 2:
Input: [-5, 2, -1, -2, 3]
Output: [[-5, 2, 3], [-2, -1, 3]]
Explanation: There are two unique triplets whose sum is equal to zero.
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
//#include <string>
//#include <unordered_map>
#include "pattern_two_pointers.hpp"
using namespace std;

static vector<vector<int>> solver(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int len = nums.size();
	vector<vector<int>> res;
	for (int i = 0; i < len - 2;i++) {
		if (i > 0 && nums[i] == nums[i - 1]) continue;

		int k = len - 1;
		for (int j = i + 1; j < k; j++) {
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
			int tar = 0 - nums[i] - nums[j];
			while (nums[k] > tar && j < k) k--;
			if (j == k) break;
			if (nums[k] == tar) {
				res.push_back({nums[i], nums[j], nums[k]});
			}
		}		
	}

	return res;
}

void triplet_sum_to_zero() {
	vector<int> nums{ -5, 2, -1, -2, 3 };
	vector<vector<int>> ans = solver(nums);

	for (int i = 0; i < ans.size();i++) {
		vector<int> t = ans[i];
		cout << '{';
		for (int j = 0; j < t.size(); j++) {
			cout << t[j] << ' ';
		}
		cout <<'}'<< endl;
	}
	system("pause");
}