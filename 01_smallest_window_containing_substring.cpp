/* Challenge 3, Hard
Problem Statement
Given a string and a pattern, find the smallest substring in the given string which has all the characters of the given pattern.
Example 1:
Input: String="aabdec", Pattern="abc"
Output: "abdec"
Explanation: The smallest substring having all characters of the pattern is "abdec"
Example 2:
Input: String="abdabca", Pattern="abc"
Output: "abc"
Explanation: The smallest substring having all characters of the pattern is "abc".
Example 3:
Input: String="adcad", Pattern="abc"
Output: ""
Explanation: No substring in the given string has all characters of the pattern.*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "pattern01_sliding_window.hpp"
using namespace std;

static int chs[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

static string solver(string& ss, string& ptn) {
	int size_ss = ss.size();
	int size_ptn = ptn.size();

	for (int i = 0; i < size_ptn; i++)
		chs[ptn[i] - 'a']++;

	int left = 0, right = 0;
	int min_len = size_ss + 1;
	int subs_pos=0;
	for (; right < size_ss; right++) {
		chs[ss[right] - 'a']--;

		while (*max_element(chs, chs + 26) <= 0) {
			if (min_len > right - left + 1) {
				subs_pos = left;
				min_len = right - left + 1;
			}
			chs[ss[left] - 'a']++;
			left++;
		}
	}

	if (min_len > size_ss) return "";
	return ss.substr(subs_pos, min_len);
}

void smallest_window_containing_substring() {
	string ss = "aabdec";
	string ptn = "abc";
	string ans = solver(ss, ptn);
	cout << ans << endl;
	system("pause");
}