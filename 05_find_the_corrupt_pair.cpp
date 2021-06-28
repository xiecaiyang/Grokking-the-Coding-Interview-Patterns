/* Challenge 1, Easy
Problem Statement
We are given an unsorted array containing ¡®n¡¯ numbers taken from the range 1 to ¡®n¡¯. The array originally contained all the numbers from 1 to ¡®n¡¯, but due to a data error, one of the numbers got duplicated which also resulted in one number going missing. Find both these numbers.
Example 1:
Input: [3, 1, 2, 5, 2]
Output: [2, 4]
Explanation: '2' is duplicated and '4' is missing.
Example 2:
Input: [3, 1, 2, 3, 6, 4]
Output: [3, 5]
Explanation: '3' is duplicated and '5' is missing.
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
		if (nums[idx] != nums[i]) {
			swap(nums[i], nums[idx]);
		}
		else {
			i++;
		}
	}
	for (int j = 0; j < nums.size(); ++j) {
		if (nums[j] - 1 != j) {
			res.push_back(nums[j]);
			res.push_back(j+1);
		}
	}
	return res;
}

void find_the_corrupt_pair() {
	vector<int> objs{ 3, 1, 2, 3, 6, 4 };
	vector<int> ans = solver(objs);

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	system("pause");

}