/* Challenge 2, Hard
Problem Statement
Given a string and a pattern, find all anagrams of the pattern in the given string.
Anagram is actually a Permutation of a string. For example, ¡°abc¡± has the following six anagrams:
abc
acb
bac
bca
cab
cba
Write a function to return a list of starting indices of the anagrams of the pattern in the given string.
Example 1:
Input: String="ppqp", Pattern="pq"
Output: [1, 2]
Explanation: The two anagrams of the pattern in the given string are "pq" and "qp".
Example 2:
Input: String="abbcabc", Pattern="abc"
Output: [2, 3, 4]
Explanation: The three anagrams of the pattern in the given string are "bca", "cab", and "abc".*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "pattern_sliding_window.hpp"
using namespace std;

static int chs[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

static vector<int> solver(string& ss, string& ptn) {
	vector<int> ans;
	int size_ss = ss.size();
	int size_ptn = ptn.size();
	if (size_ss < size_ptn) return ans;

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
		if (*min_element(chs, chs + 26) == 0 && *max_element(chs, chs + 26) == 0) 
			ans.push_back(left);

	}

	return ans;
}

void string_anagrams() {
	string ss = "abbcabc";
	string ptn = "abc";
	vector<int> ans = solver(ss, ptn);
	cout << '[' ;
	for (int i = 0; i < ans.size();i++) {
		cout << ans[i];
		if (i < ans.size() - 1) cout << ',';
	}
	cout << ']' << endl;
	system("pause");
}