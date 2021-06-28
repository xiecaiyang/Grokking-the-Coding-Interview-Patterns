/* Easy
Problem Statement
We are given an array containing ��n�� objects. Each object, when created, was assigned a unique number from 1 to ��n�� based on their creation sequence.
This means that the object with sequence number ��3�� was created just before the object with sequence number ��4��.
Write a function to sort the objects in-place on their creation sequence number in O(n) and without any extra space.
For simplicity, let��s assume we are passed an integer array containing only the sequence numbers, though each number is actually an object.
Example 1:
Input: [3, 1, 5, 4, 2]
Output: [1, 2, 3, 4, 5]
Example 2:
Input: [2, 6, 4, 3, 1, 5]
Output: [1, 2, 3, 4, 5, 6]
Example 3:
Input: [1, 5, 6, 4, 3, 2]
Output: [1, 2, 3, 4, 5, 6]
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern05_cyclic_sort.hpp"
using namespace std;



static vector<int> solver(vector<int>& nums) {
	int i = 0;
	while (i<nums.size()) {
		int j = nums[i] - 1;
		if (i != j) {
			swap(nums[i],nums[j]);
		}
		else {
			i++;
		}
	}

	return nums;
}

void cyclic_sort() {
	vector<int> objs{ 1, 5, 6, 4, 3, 2 };
	vector<int> ans = solver(objs);

	cout << "{ ";
	for (vector<int>::iterator iter = ans.begin(); iter != ans.end(); ++iter) {
		cout << *iter << ' ';
	}
	cout << "}" << endl;
	system("pause");

}