/* Medium
Given a binary tree where each node can only have a digit (0-9) value,
each root-to-leaf path will represent a number. Find the total sum of all the numbers represented by all paths.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern07_tree_breadth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;

void calc_path(TreeNode* node, int path_value, int& sum) {
	path_value = path_value * 10 + node->val;
	if (!node->left && !node->right) {
		sum += path_value;
	}
	else {
		if (node->left) calc_path(node->left, path_value, sum);
		if (node->right) calc_path(node->right, path_value, sum);
	}
}

static int solver(TreeNode* root) {
	int sum = 0;
	calc_path(root, 0, sum);

	return sum;
}

void sum_of_path_numbers() {
	/*     1
		  / \
		 2   4
		/   / \
	   1   8   9     */
	TreeNode root(1);
	root.left = &TreeNode(2);
	root.right = &TreeNode(4);
	root.left->left = &TreeNode(1);
	root.right->left = &TreeNode(8);
	root.right->right = &TreeNode(9);

	
	//root.left->left->left = &TreeNode(3);

	int ans = solver(&root);


	
	cout << ans << endl;

	system("pause");

}