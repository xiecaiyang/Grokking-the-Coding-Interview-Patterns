/* Medium
Problem Statement
Given a binary tree, populate an array to represent its zigzag level order traversal.
You should populate the values of all nodes of the first level from left to right,
then right to left for the next level and keep alternating in the same manner for the following levels.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern07_tree_breadth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;



static vector<vector<int>> solver(TreeNode* root) {
	vector<vector<int>> res;
	deque<TreeNode*> myque;
	myque.push_back(root);
	bool left2right = true;

	while (!myque.empty()) {
		int cnt = myque.size();
		deque<int> curlevel;
		while (cnt) {
			TreeNode * curNode = myque.front();
			myque.pop_front();
			--cnt;
			if (left2right) {
				curlevel.push_back(curNode->val);
			}
			else {
				curlevel.push_front(curNode->val);
			}
						
			if (curNode->left) myque.push_back(curNode->left);
			if (curNode->right) myque.push_back(curNode->right);			
		}
		vector<int> temp(curlevel.begin(), curlevel.end());
		res.push_back(temp);
		left2right = !left2right;
	}

	return res;
}

void zigzag_traversal() {
	/*     12
	      /  \
		 7    1
		/    / \
	   9    10  5   
		   /  \	  
		  20  17    */
	TreeNode root(12);
	root.left = &TreeNode(7);
	root.right = &TreeNode(1);
	root.left->left = &TreeNode(9);
	root.right->left = &TreeNode(10);
	root.right->right = &TreeNode(5);
	root.right->left->left = &TreeNode(20);
	root.right->left->right = &TreeNode(17);

	vector<vector<int>> ans = solver(&root);

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