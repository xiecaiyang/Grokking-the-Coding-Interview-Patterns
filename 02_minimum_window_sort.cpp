/* Medium
Problem Statement
Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.
Example 1:
Input: [1, 2, 5, 3, 7, 10, 9, 12]
Output: 5
Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted
Example 2:
Input: [1, 3, 2, 0, -1, 7, 10]
Output: 5
Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted
Example 3:
Input: [1, 2, 3]
Output: 0
Explanation: The array is already sorted
Example 4:
Input: [3, 2, 1]
Output: 3
Explanation: The whole array needs to be sorted.
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
//#include <string>
//#include <unordered_map>
#include "pattern02_two_pointers.hpp"
using namespace std;

static int solver(vector<int>& nums) {
	int len = nums.size();
	int i = 0;
	while (i < len) {
		if (i > 0 && nums[i - 1] > nums[i]) {
			break;
		}
		i++;
	}
	if (i == len) return 0;

	int j = len - 1;
	while (j >= 0) {
		if (j<len - 1 && nums[j]> nums[j + 1]) {
			break;
		}
		j--;
	}

	int max_value = nums[max_element(nums.begin()+i, nums.begin()+j+1) - nums.begin()];
	int min_value = nums[min_element(nums.begin()+i, nums.begin()+j+1) - nums.begin()];
	
	while (i > 0) {
		if (nums[i-1] > min_value) i--;
		else break;
	}
	while (j < len - 1) {
		if (nums[j+1] < max_value) j++;
		else break;
	}

	return j-i+1;
}

void minimum_window_sort() {
	vector<int> nums{ 3, 2, 1 };
	int ans = solver(nums);
	cout << ans << endl;

	system("pause");
}