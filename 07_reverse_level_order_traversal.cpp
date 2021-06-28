/* Easy
Problem Statement
Given a binary tree, populate an array to represent its level-by-level traversal in reverse order, i.e., the lowest level comes first.
You should populate the values of all nodes in each level from left to right in separate sub-arrays.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern07_tree_breadth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;



static deque<vector<int>> solver(TreeNode* root) {
	deque<vector<int>> res;
	queue<TreeNode*> myque;
	myque.push(root);

	while (!myque.empty()) {
		int cnt = myque.size();
		vector<int> curlevel;
		while (cnt) {
			TreeNode * curNode = myque.front();
			myque.pop();
			--cnt;
			curlevel.push_back(curNode->val);
			if (curNode->left) myque.push(curNode->left);
			if (curNode->right) myque.push(curNode->right);
		}
		res.push_front(curlevel);
	}

	return res;
}

void reverse_level_order_traversal() {
	/*     12
	      /  \
	     7    1
	    /    / \
	   9    10  5   */	
	TreeNode root(12);
	root.left = &TreeNode(7);             
	root.right = &TreeNode(1);			  
	root.left->left = &TreeNode(9);       
	root.right->left = &TreeNode(10);     
	root.right->right = &TreeNode(5);     

	deque<vector<int>> ans = solver(&root);

	cout << "{";
	for (int i = 0; i < ans.size(); ++i) {
		cout << '{';
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << "\b}";
	}
	cout << "}" << endl;
	system("pause");

}