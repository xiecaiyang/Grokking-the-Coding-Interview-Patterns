/* Medium
Given a binary tree and a number ¡®S¡¯,
find all paths in the tree such that the sum of all the node values of each path equals ¡®S¡¯.
Please note that the paths can start or end at any node but all paths must follow direction from parent to child (top to bottom).
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern08_tree_depth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;

void count_paths(TreeNode* node, int target, int& count) {
	if (!node) return;
	if (node->val == target) count++;
	count_paths(node->left, target, count);
	count_paths(node->right, target, count);
	count_paths(node->left, target - node->val, count);
	count_paths(node->right, target - node->val, count);
}

static int solver(TreeNode* root, int target) {
	int count = 0;
	count_paths(root, target, count);
	return count;
}

void count_paths_for_a_sum() {
	/*      1
		  /  \
		 7    9
		/ \  / \
	   6  5  2  3   */
	TreeNode root(1);
	root.left = &TreeNode(7);
	root.right = &TreeNode(9);
	root.left->left = &TreeNode(6);
	root.left->right = &TreeNode(5);
	root.right->left = &TreeNode(2);
	root.right->right = &TreeNode(3);


	//root.left->left->left = &TreeNode(3);

	int ans = solver(&root, 12);



	cout << ans << endl;

	system("pause");

}