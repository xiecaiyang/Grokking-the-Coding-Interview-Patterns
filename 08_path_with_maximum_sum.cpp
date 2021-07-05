/* Problem Challenge 2, Hard
Find the path with the maximum sum in a given binary tree. Write a function that returns the maximum sum.
A path can be defined as a sequence of nodes between any two nodes and doesn¡¯t necessarily pass through the root.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern08_tree_depth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;

int find_max_sum_depth(TreeNode* node, int& max_sum) {
	if (!node) return 0;
	int left_depth = find_max_sum_depth(node->left, max_sum);
	int right_depth = find_max_sum_depth(node->right, max_sum);
	max_sum = max(max_sum, left_depth + right_depth+node->val);

	return max(left_depth, right_depth) + node->val;
}

static int solver(TreeNode* root) {
	int max_sum = INT_MIN;
	find_max_sum_depth(root, max_sum);
	return max_sum;
}

void path_with_maximum_sum() {
	/*      1
		  /  \
		 2    3
		/\   / \
	   1  3 5   6
		   /\   /
		  7 8  9       */
	/*TreeNode root(1);
	root.left = &TreeNode(2);
	root.right = &TreeNode(3);

	root.left->left = &TreeNode(1);
	root.left->right = &TreeNode(3);
	root.right->left = &TreeNode(5);
	root.right->right = &TreeNode(6);
	root.right->left->left = &TreeNode(7);
	root.right->left->right = &TreeNode(8);
	root.right->right->left = &TreeNode(9);*/

	TreeNode root = TreeNode(-1);
	root.left = &TreeNode(-3);
	int ans = solver(&root);


	cout << ans << endl;

	system("pause");

}