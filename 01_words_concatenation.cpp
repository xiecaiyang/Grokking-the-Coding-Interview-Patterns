/* Challenge 3, Hard
Problem Statement
Given a string and a list of words, find all the starting indices of substrings in the given string that are a concatenation of all the given words exactly once without any overlapping of words. 
It is given that all words are of the same length.
Example 1:
Input: String="catfoxcat", Words=["cat", "fox"]
Output: [0, 3]
Explanation: The two substring containing both the words are "catfox" & "foxcat".
Example 2:
Input: String="catcatfoxfox", Words=["cat", "fox"]
Output: [3]
Explanation: The only substring containing both the words is "catfox".*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "pattern01_sliding_window.hpp"
using namespace std;

static int chs[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

static vector<int> solver(string& ss, vector<string>& words) {
	int size_ss = ss.size();
	int size_word = words[0].size();
	int num_word = words.size();
	vector<int> res;

	for (int i = 0; i < size_ss - num_word*size_word + 1; i++) {
		unordered_map<string, int> mymap;
		for (auto word : words) {
			mymap[word]++;
		}
		bool exp_word = false;
		for (int j = 0; j < num_word; j++) {
			string cur_word = ss.substr(i+j*size_word, size_word);
			if (mymap.find(cur_word) == mymap.end()) {
				exp_word = true;
				break;
			}
			else {
				mymap[cur_word]--;
				if (!mymap[cur_word]) {
					mymap.erase(cur_word);
				}
			}
		}
		if (exp_word) continue;
		if (!mymap.size()) {
			res.push_back(i);
		}
	}
		
	return res;
}

void words_concatenation() {
	string ss = "cfxoatcatfoxfox";
	string word1 = "cat";
	string word2 = "fox";
	vector<string> words{ word1, word2 };
	vector<int> ans = solver(ss, words);
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << endl;
	system("pause");
}