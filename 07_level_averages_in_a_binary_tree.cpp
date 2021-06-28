/* Easy
Problem Statement
Given a binary tree, populate an array to represent the averages of all of its levels.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern07_tree_breadth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;



static vector<int> solver(TreeNode* root) {
	vector<int> res;
	queue<TreeNode*> myque;
	myque.push(root);

	while (!myque.empty()) {
		int cnt = myque.size();
		int sum = 0;
		int i = 0;
		while (i<cnt) {
			TreeNode * curNode = myque.front();
			myque.pop();
			++i;
			sum+=curNode->val;
			if (curNode->left) myque.push(curNode->left);
			if (curNode->right) myque.push(curNode->right);
		}
		res.push_back(sum/cnt);
	}

	return res;
}

void level_averages_in_a_binary_tree() {
	/*     12
	      /  \
	     7    1
	    / \  / \
	   9  2 10  5   */
	TreeNode root(12);
	root.left = &TreeNode(7);
	root.right = &TreeNode(1);
	root.left->left = &TreeNode(9);
	root.left->right = &TreeNode(2);
	root.right->left = &TreeNode(10);
	root.right->right = &TreeNode(7);

	vector<int> ans = solver(&root);

	cout << "{";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	cout << "\b}" << endl;
	system("pause");

}