/* Challenge 1, Hard
Problem Statement
Given a string and a pattern, find out if the string contains any permutation of the pattern.
Permutation is defined as the re-arranging of the characters of the string. For example, ¡°abc¡± has the following six permutations:
abc
acb
bac
bca
cab
cba
If a string has ¡®n¡¯ distinct characters it will have n!n! permutations.
Example 1:
Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.
Example 2:
Input: String="odicf", Pattern="dc"
Output: false
Explanation: No permutation of the pattern is present in the given string as a substring.
Example 3:
Input: String="bcdxabcdy", Pattern="bcdyabcdx"
Output: true
Explanation: Both the string and the pattern are a permutation of each other.
Example 4:
Input: String="aaacb", Pattern="abc"
Output: true
Explanation: The string contains "acb" which is a permutation of the given pattern.*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "pattern_sliding_window.hpp"
using namespace std;

static int chs[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

static bool solver(string& ss, string& ptn) {
	int size_ss = ss.size();
	int size_ptn = ptn.size();
	if (size_ss < size_ptn) return false;

	//for (int i = 0; i + size_ptn < size_ss + 1; i++) {
	//	if (is_permutation(ss.begin() + i, ss.begin() + i + size_ptn, ptn.begin(), ptn.end()));
	//		return true;

	//}
	for (int i = 0; i < size_ptn; i++)
		chs[ptn[i] - 'a']++;
	
	int left = 0, right = 0;
	for (; right < size_ss; right++) {
		chs[ss[right] - 'a']--;
		
		if (right >= size_ptn) {
			chs[ss[left] - 'a']++;
			left++;
		}
		if (*min_element(chs, chs + 26) == 0 && *max_element(chs, chs + 26) == 0) return true;

	}

	return false;
}

void permutation_in_a_string() {
	string ss = "aaacb";
	string ptn = "abc";
	bool ans = solver(ss, ptn);
	cout << ans << endl;
	system("pause");
}