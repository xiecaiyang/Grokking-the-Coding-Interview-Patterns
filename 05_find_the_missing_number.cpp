/* Easy
Problem Statement
We are given an array containing ¡®n¡¯ distinct numbers taken from the range 0 to ¡®n¡¯.
Since the array has only ¡®n¡¯ numbers out of the total ¡®n+1¡¯ numbers, find the missing number.
Example 1:
Input: [4, 0, 3, 1]
Output: 2
Example 2:
Input: [8, 3, 5, 2, 4, 6, 0, 1]
Output: 7
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern05_cyclic_sort.hpp"
using namespace std;

static int solver(vector<int>& nums) {
	int i = 0;
	while (i<nums.size()) {
		if (nums[i]<nums.size() && i != nums[i]) {
			swap(nums[i], nums[nums[i]]);
		}
		else {
			i++;
		}
	}

	for (int j = 0; j < nums.size(); j++) {
		if (j != nums[j])
			return j;
	}

	return nums.size();
}

void find_the_missing_number() {
	vector<int> objs{ 8, 3, 5, 2, 4, 6, 0, 1 };
	int ans = solver(objs);

	
	cout << ans << endl;
	system("pause");

}