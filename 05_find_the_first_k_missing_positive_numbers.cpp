/* Challenge 3, Hard
Given an unsorted array containing numbers and a number ¡®k¡¯, find the first ¡®k¡¯ missing positive numbers in the array.
Example 1:
Input: [3, -1, 4, 5, 5], k=3
Output: [1, 2, 6]
Explanation: The smallest missing positive numbers are 1, 2 and 6.
Example 2:
Input: [2, 3, 4], k=3
Output: [1, 5, 6]
Explanation: The smallest missing positive numbers are 1, 5 and 6.
Example 3:
Input: [-2, -3, 4], k=2
Output: [1, 2]
Explanation: The smallest missing positive numbers are 1 and 2.
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <unordered_set>
#include "pattern05_cyclic_sort.hpp"
using namespace std;

static vector<int> solver(vector<int>& nums, int& k) {
	vector<int> res;
	unordered_set<int> extra_nums;
	int i = 0;
	while (i < nums.size()) {
		int j = nums[i] - 1;
		if (j >= 0 && j < nums.size() && nums[i] != nums[j]) {
			swap(nums[i], nums[j]);
		}
		else
			++i;
	}
	for (int j = 0; j < nums.size(); ++j) {
		if (nums[j] - 1 != j) {
			--k;
			res.push_back(j+1);
			extra_nums.insert(nums[j]);
		}
		if (!k) {
			return res;
		}
			
	}
	int adding_num = nums.size()+1;
	while (k > 0) {
		if (extra_nums.find(adding_num) == extra_nums.end()) {
			res.push_back(adding_num);
			--k;		
		}
		++adding_num;
	}


	return res;
}

void find_the_first_k_missing_positive_numbers() {
	vector<int> objs{ -2, -3, 4 };
	int k = 2;
	vector<int> ans = solver(objs, k);

	cout << "{";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i]<<' ';
	}
	cout << '}' << endl;
	system("pause");

}