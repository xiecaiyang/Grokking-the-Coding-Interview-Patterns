/* Medium
Problem Statement
Given a binary tree, connect each node with its level order successor.
The last node of each level should point to a null node.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern07_tree_breadth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;



static void solver(TreeNodeSuccessor* root) {
	queue<TreeNodeSuccessor*> myque;
	myque.push(root);

	while (!myque.empty()) {
		int cnt = myque.size();

		while (cnt) {
			TreeNodeSuccessor * curNode = myque.front();
			myque.pop();
			cnt--;
			if (curNode->left) myque.push(curNode->left);
			if (curNode->right) myque.push(curNode->right);

			curNode->next = cnt ? myque.front() : nullptr;
		}
	}

}

void connect_level_order_siblings() {
	/*     12
		  /  \
		 7    1
		/    / \
	   9    10  5
		            */
	TreeNodeSuccessor root(12);
	root.left = &TreeNodeSuccessor(7);
	root.right = &TreeNodeSuccessor(1);
	root.right->left = &TreeNodeSuccessor(10);
	root.right->right = &TreeNodeSuccessor(5);

	root.left->left = &TreeNodeSuccessor(9);
	//root.right->left->left = &TreeNode(11);


	solver(&root);

	root.print_level_order();
	system("pause");

}