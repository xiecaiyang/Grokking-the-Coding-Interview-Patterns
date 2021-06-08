/* Easy
Problem Statement
Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.
Example 1:
Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
Example 2:
Input: [-3, -1, 0, 1, 2]
Output: [0 1 1 4 9] 
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
//#include <algorithm>
//#include <string>
//#include <unordered_map>
#include "pattern_two_pointers.hpp"
using namespace std;

static vector<int> solver(vector<int>& nums) {
	int len = nums.size();
	int i = 0, j = len - 1;
	vector<int> res(len, 0);
	for (int k=len-1; k >=0; k--) {
		if (abs(nums[i]) > abs(nums[j]) ){
			res[k] = nums[i] * nums[i];
			i++;
		}
		else {
			res[k] = nums[j] * nums[j];
			j--;
		}
	}

	return res;
}

void squaring_a_sorted_array() {
	vector<int> nums{ -3, -1, 0, 1, 2 };
	vector<int> ans = solver(nums);
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << endl;
	system("pause");
}