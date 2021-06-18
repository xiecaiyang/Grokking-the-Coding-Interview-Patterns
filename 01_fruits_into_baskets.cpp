/* Medium
Problem Statement
Given an array of characters where each character represents a fruit tree, you are given two baskets and your goal is to put maximum number of fruits in each basket. The only restriction is that each basket can have only one type of fruit.
You can start with any tree, but once you have started you can¡¯t skip a tree. You will pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.
Write a function to return the maximum number of fruits in both the baskets.
Example 1:
Input: Fruit=['A', 'B', 'C', 'A', 'C']
Output: 3
Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']
Example 2:
Input: Fruit=['A', 'B', 'C', 'B', 'B', 'C']
Output: 5
Explanation: We can put 3 'B' in one basket and two 'C' in the other basket.
This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C'] */

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map>
#include "pattern01_sliding_window.hpp"
using namespace std;

static int solver(vector<char>& nums) {
	unordered_map<char, int> mymap;
	int left = 0, right = 0;
	int max_len = 0;
	for (; right < nums.size(); right++) {
		unordered_map<char, int>::iterator got = mymap.find(nums[right]);
		if (got == mymap.end()) {
			mymap.insert(make_pair(nums[right], 1));
		}
		else {
			got->second++;
		}
		while (mymap.size() > 2) {
			//mymap[ss[left]]--;
			if (!--mymap[nums[left]]) {
				mymap.erase(nums[left]);
			}
			left++;
		}
		max_len = max(max_len, right - left + 1);
	}
	return max_len;
}

void fruits_into_baskets() {
	vector<char> nums{ 'A', 'B', 'C', 'B', 'B', 'C' };
	int ans = solver(nums);
	cout << ans << endl;
	system("pause");
}