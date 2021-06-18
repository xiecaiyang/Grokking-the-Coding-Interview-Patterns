/* Easy
Problem Statement
Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.
Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target.
Example 1:
Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
Example 2:
Input: [2, 5, 9, 11], target=11
Output: [0, 2]
Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "pattern02_two_pointers.hpp"
using namespace std;

static vector<int> solver(vector<int>& nums, int target) {
	int len = nums.size();
	vector<int> res;
	for (int i = 0, j = len - 1; i < j;) {
		if (nums[i] + nums[j] < target) {
			i++;
		}
		else if (nums[i] + nums[j] > target) {
			j--;
		}
		else {
			res.push_back(i);
			res.push_back(j);
			break;

		}
	}
	return res;
}

void pair_with_target_sum() {
	vector<int> nums{ 2, 5, 9, 11 };
	int target = 11;
	vector<int> ans = solver(nums, target);
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout <<  endl;
	system("pause");
}