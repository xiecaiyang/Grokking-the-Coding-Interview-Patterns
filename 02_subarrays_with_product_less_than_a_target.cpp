/* Medium
Problem Statement
Given an array with positive numbers and a target number,
find all of its contiguous subarrays whose product is less than the target number.
Example 1:
Input: [2, 5, 3, 10], target=30
Output: [2], [5], [2, 5], [3], [5, 3], [10]
Explanation: There are six contiguous subarrays whose product is less than the target.
Example 2:
Input: [8, 2, 6, 5], target=50
Output: [8], [2], [8, 2], [6], [2, 6], [5], [6, 5]
Explanation: There are seven contiguous subarrays whose product is less than the target.
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
//#include <string>
//#include <unordered_map>
#include "pattern_two_pointers.hpp"
using namespace std;

static vector<vector<int>> solver(vector<int>& nums, int& target) {
	int len = nums.size();
	vector<vector<int>> res;
	int product = 1;
	int left = 0;
	for (int right = 0; right < len; right++) {
		product *= nums[right];
		
		while (product >= target && left<=right) {
			product /= nums[left];
			left++;
		}
		vector<int> temp;
		for (int i = right; i >=left; i--) {
			temp.push_back(nums[i]);
			res.push_back(temp);
		}
	}
	return res;
}
static vector<vector<int>> solver2(vector<int>& nums, int& target) {
	int len = nums.size();
	vector<vector<int>> res;
	for (int i = 0; i < len; i++) {
		if (nums[i] < target) res.push_back({ nums[i] });
		else continue;
		int product = nums[i];
		for (int j = i + 1; j < len; j++) {
			product *= nums[j];
			if (product >= target)
				break;
			else {
				vector<int> temp;
				for (int k = i; k <= j; k++) temp.push_back(nums[k]);
				res.push_back(temp);
			}
		}
	}

	return res;
}

void subarrays_with_product_less_than_a_target() {
	vector<int> nums{ 2, 5, 3, 10 };
	int target = 30;
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