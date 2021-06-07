/* Hard
Problem Statement
Given a string with lowercase letters only, if you are allowed to replace no more than ¡®k¡¯ letters with any letter, find the length of the longest substring having the same letters after replacement.
Example 1:
Input: String="aabccbb", k=2
Output: 5
Explanation: Replace the two 'c' with 'b' to have a longest repeating substring "bbbbb".
Example 2:
Input: String="abbcb", k=1
Output: 4
Explanation: Replace the 'c' with 'b' to have a longest repeating substring "bbbb".
Example 3:
Input: String="abccde", k=1
Output: 3
Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating substring "ccc".*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "pattern_sliding_window.hpp"
using namespace std;

static int chs[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

static int solver(string& ss, int k) {
	int left = 0, right = 0;
	for (; right < ss.size(); right++) {
		chs[ss[right] - 'a']++;
		if (*max_element(chs, chs + 26) + k < right - left + 1) {
			chs[ss[left] - 'a']--;
			left++;
		}
	}
	return right - left;
}

void longest_substring_with_same_letters_after_replacement() {
	string ss = "abbbbcbccbde";
	int k = 2;
	int ans = solver(ss, k);
	cout << ans << endl;
	system("pause");
}