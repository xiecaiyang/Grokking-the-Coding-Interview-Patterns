/* Medium
Problem Statement
Find the minimum depth of a binary tree.
The minimum depth is the number of nodes along the shortest path from the root node to the nearest leaf node.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern07_tree_breadth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;



static int solver(TreeNode* root) {
	deque<TreeNode*> myque;
	myque.push_back(root);
	int depth = 0;
	while (!myque.empty()) {
		++depth;
		int cnt = myque.size();
		
		while (cnt) {
			TreeNode * curNode = myque.front();
			myque.pop_front();
			--cnt;
			if (!curNode->left && !curNode->right) {
				return depth;
			}
			else {
				if (curNode->left) myque.push_back(curNode->left);
				if (curNode->right) myque.push_back(curNode->right);
			}

		}
	}

	return depth;
}

void minimum_depth_of_a_binary_tree() {
	/*     12
		  /  \
		 7    1
		/    / \
	   9    10  5
		   /  
		  11        */
	TreeNode root(12);
	root.left = &TreeNode(7);
	root.right = &TreeNode(1);	
	root.right->left = &TreeNode(10);
	root.right->right = &TreeNode(5);

	root.left->left = &TreeNode(9);
	root.right->left->left = &TreeNode(11);


	int ans = solver(&root);

	cout << ans << endl;
	system("pause");

}