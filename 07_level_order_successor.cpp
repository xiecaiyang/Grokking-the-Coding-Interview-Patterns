/* Easy
Problem Statement
Given a binary tree and a node, find the level order successor of the given node in the tree.
The level order successor is the node that appears right after the given node in the level order traversal.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern07_tree_breadth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;



static TreeNode* solver(TreeNode* root, int key) {
	queue<TreeNode*> myque;
	myque.push(root);

	while (!myque.empty()) {
		TreeNode * curNode = myque.front();
		myque.pop();

		if (curNode->left) myque.push(curNode->left);
		if (curNode->right) myque.push(curNode->right);

		if (curNode->val == key) break;		
	}

	if (!myque.empty()) return myque.front();
	else return nullptr;
}

void level_order_successor() {
	/*     12
		  /  \
		 7    1
		/    / \
	   9    10  5   */
	TreeNode root(12);
	root.left = &TreeNode(7);
	root.right = &TreeNode(1);
	root.left->left = &TreeNode(9);
	//root.left->right = &TreeNode(2);
	root.right->left = &TreeNode(10);
	root.right->right = &TreeNode(5);

	TreeNode* ans = solver(&root, 9);

	
	cout << ans->val << endl;
	system("pause");

}