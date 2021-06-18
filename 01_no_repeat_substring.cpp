/* Hard
Problem Statement
Given a string, find the length of the longest substring which has no repeating characters.
Example 1:
Input: String="aabccbb"
Output: 3
Explanation: The longest substring without any repeating characters is "abc".
Example 2:
Input: String="abbbb"
Output: 2
Explanation: The longest substring without any repeating characters is "ab".
Example 3:
Input: String="abccde"
Output: 3
Explanation: Longest substrings without any repeating characters are "abc" & "cde". */

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "pattern01_sliding_window.hpp"
using namespace std;

static int solver(string& ss) {
	unordered_map<char, int> mymap;
	int left = 0, right = 0;
	int max_len = 0;
	for (; right < ss.size(); right++) {
		mymap[ss[right]]++;
		while (mymap[ss[right]] > 1) {
			mymap[ss[left]]--;
			left++;
		}
		max_len = max(max_len, right - left + 1);
	}
	return max_len;
}

void no_repeat_substring() {
	string ss = "abccde";
	int ans = solver(ss);
	cout << ans << endl;
	system("pause");
}