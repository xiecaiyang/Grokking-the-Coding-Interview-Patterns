/* Medium
Problem Statement
Comparing Strings containing Backspaces (medium)
Given two strings containing backspaces (identified by the character ¡®#¡¯), check if the two strings are equal.
Example 1:
Input: str1="xy#z", str2="xzz#"
Output: true
Explanation: After applying backspaces the strings become "xz" and "xz" respectively.
Example 2:
Input: str1="xy#z", str2="xyz#"
Output: false
Explanation: After applying backspaces the strings become "xz" and "xy" respectively.
Example 3:
Input: str1="xp#", str2="xyz##"
Output: true
Explanation: After applying backspaces the strings become "x" and "x" respectively.
In "xyz##", the first '#' removes the character 'z' and the second '#' removes the character 'y'.
Example 4:
Input: str1="xywrrmp", str2="xywrrmu#p"
Output: true
Explanation: After applying backspaces the strings become "xywrrmp" and "xywrrmp" respectively.
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
//#include <unordered_map>
#include "pattern02_two_pointers.hpp"
using namespace std;

int get_next_valid_char(string& ss, int idx) {
	int back_cnt = 0;
	while (idx>=0) {
		if (ss[idx] == '#') {
			back_cnt++;
			idx--;
		}
		else if (back_cnt > 0) {
			back_cnt--;
			idx--;
		}
		else
			break;
	}
	return idx;
}

static bool solver(string& s1, string& s2) {
	int idx1 = s1.size() - 1;
	int idx2 = s2.size() - 1;
	while (idx1 >= 0 || idx2 >= 0) {
		int i1 = get_next_valid_char(s1, idx1);
		int i2 = get_next_valid_char(s2, idx2);
		if (i1 < 0 && i2 < 0)
			return true;
		else if (i1 < 0 || i2 < 0)
			return false;
		else if (s1[i1] != s2[i2])
			return false;

		idx1 = i1 - 1;
		idx2 = i2 - 1;
	}

	return true;
}

void comparing_strings_containing_backspaces() {
	string s1 = "xywrrmp";
	string s2 = "xywrrmu#p";
	bool ans = solver(s1, s2);
	cout << ans << endl;

	system("pause");
}