/* Easy
Problem Statement
We are given an unsorted array containing ¡®n+1¡¯ numbers taken from the range 1 to ¡®n¡¯.
The array has only one duplicate but it can be repeated multiple times.
Find that duplicate number without using any extra space. You are, however, allowed to modify the input array.
Example 1:
Input: [1, 4, 4, 3, 2]
Output: 4
Example 2:
Input: [2, 1, 3, 3, 5, 4]
Output: 3
Example 3:
Input: [2, 4, 1, 4, 4]
Output: 4
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern05_cyclic_sort.hpp"
using namespace std;

static int solver(vector<int>& nums) {
	while (nums[0]!=nums[nums[0]]) {
		swap(nums[0],nums[nums[0]]);
	}

	return nums[0];
}

void find_the_duplicate_number() {
	vector<int> objs{ 2, 4, 1, 4, 4 };
	int ans = solver(objs);


	cout << ans << endl;
	system("pause");

}