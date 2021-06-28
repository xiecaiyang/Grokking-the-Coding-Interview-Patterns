/* Easy
Problem Statement
We are given an unsorted array containing ¡®n¡¯ numbers taken from the range 1 to ¡®n¡¯.
The array has some duplicates, find all the duplicate numbers without using any extra space.
Example 1:
Input: [3, 4, 4, 5, 5]
Output: [4, 5]
Example 2:
Input: [5, 4, 7, 2, 3, 5, 3]
Output: [3, 5]
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern05_cyclic_sort.hpp"
using namespace std;

static vector<int> solver(vector<int>& nums) {
	vector<int> res;
	int i = 0;
	while (i<nums.size()) {
		int idx = nums[i] - 1;
		if (nums[idx]!=nums[i]) {  
			swap(nums[i], nums[idx]);
		}
		else {
			i++;
		}
	}
	for (int j = 0; j < nums.size(); ++j) {
		if (nums[j] - 1 != j) res.push_back(nums[j]);
	}
	return res;
}

void find_all_duplicate_numbers() {
	vector<int> objs{ 5, 4, 7, 2, 3, 5, 3 };
	vector<int> ans = solver(objs);

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	system("pause");

}