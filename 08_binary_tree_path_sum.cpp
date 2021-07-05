/* Easy
Given a binary tree and a number ¡®S¡¯,
find if the tree has a path from root-to-leaf such that the sum of all the node values of that path equals ¡®S¡¯.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern08_tree_depth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;

static bool solver(TreeNode* root, int sum) {
	if (!root) return false;

	if (!root->left && !root->right) { // leaf node
		if (sum == root->val) return true;
		else return false;
	}
	else {
		return solver(root->left, sum - root->val) || solver(root->right, sum - root->val);
	}
}

void binary_tree_path_sum() {
	/*     12
		  /  \
		 7    1
		/    / \
	   9    10  5     */
	TreeNode root(12);
	root.left = &TreeNode(7);
	root.right = &TreeNode(1);
	root.right->left = &TreeNode(10);
	root.right->right = &TreeNode(5);

	root.left->left = &TreeNode(9);
	//root.left->left->left = &TreeNode(3);


	bool ans = solver(&root, 16);

	
	cout << ans << endl;

	system("pause");

}