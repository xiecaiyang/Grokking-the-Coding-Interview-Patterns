/* Medium
Problem Statement
Given a string, find the length of the longest substring in it with no more than K distinct characters.
Example 1:
Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".
Example 2:
Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".
Example 3:
Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "pattern_sliding_window.hpp"
using namespace std;

static int solver(string& ss, int K) {
	unordered_map<char, int> mymap;
	int left = 0, right = 0;
	int max_len = 0;
	for (; right < ss.size(); right++) {
		unordered_map<char, int>::iterator got = mymap.find(ss[right]);
		if (got == mymap.end()) {
			mymap.insert(make_pair(ss[right],1));
		}
		else {
			got->second++;
		}
		while (mymap.size() > K) {
			//mymap[ss[left]]--;
			if (!--mymap[ss[left]]) {
				mymap.erase(ss[left]);
			}
			left++;
		}
		max_len = max(max_len, right - left + 1);
	}
	return max_len;
}

void longest_substring_with_k_distinct_characters() {
	string ss = "cbbebi";
	int K = 3;
	int ans = solver(ss, K);
	cout << ans << endl;
	system("pause");
}