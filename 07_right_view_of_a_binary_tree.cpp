/* Challenge 2, Easy
Problem Statement
Given a binary tree, return an array containing nodes in its right view.
The right view of a binary tree is the set of nodes visible when the tree is seen from the right side.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern07_tree_breadth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;

static vector<TreeNode*> solver(TreeNode* root) {
	queue<TreeNode*> myque;
	myque.push(root);
	vector<TreeNode*> res;

	while (!myque.empty()) {
		int len = myque.size(),i=0;
		while (i < len) {
			TreeNode * curNode = myque.front();
			myque.pop();

			if (curNode->left) myque.push(curNode->left);
			if (curNode->right) myque.push(curNode->right);
			++i;
			if (i == len) res.push_back(curNode);
		}		
	}

	return res;
}

void right_view_of_a_binary_tree() {
	/*     12
		  /  \
		 7    1
		/    / \
	   9    10  5
	  /
	 3                 */
	TreeNode root(12);
	root.left = &TreeNode(7);
	root.right = &TreeNode(1);
	root.right->left = &TreeNode(10);
	root.right->right = &TreeNode(5);

	root.left->left = &TreeNode(9);
	root.left->left->left = &TreeNode(3);


	vector<TreeNode*> ans = solver(&root);

	for (auto item:ans) {
		cout << item->val << ' ';
	}
	cout << endl;
	
	system("pause");

}