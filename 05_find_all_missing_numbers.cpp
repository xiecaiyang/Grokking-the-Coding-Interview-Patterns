/* Easy
Problem Statement
We are given an unsorted array containing numbers taken from the range 1 to ¡®n¡¯.
The array can have duplicates, which means some numbers will be missing. Find all those missing numbers.
Example 1:
Input: [2, 3, 1, 8, 2, 3, 5, 1]
Output: 4, 6, 7
Explanation: The array should have all numbers from 1 to 8, due to duplicates 4, 6, and 7 are missing.
Example 2:
Input: [2, 4, 1, 2]
Output: 3
Example 3:
Input: [2, 3, 2, 1]
Output: 4
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
		if (idx != i && nums[idx]-1!=idx) {  //"if(nums[i]!=nums[idx])" is more short, less readable but practical
			swap(nums[i], nums[idx]);
		}
		else {
			i++;
		}
	}

	for (int j = 0; j < nums.size(); ++j) {
		if (j != nums[j]-1)
			res.push_back(j+1);
	}

	return res;
}

void find_all_missing_numbers() {
	vector<int> objs{ 2, 3, 2, 1 };
	vector<int> ans = solver(objs);

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	system("pause");

}