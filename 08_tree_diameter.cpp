/* Problem Challenge 1, Medium
Given a binary tree, find the length of its diameter.
The diameter of a tree is the number of nodes on the longest path between any two leaf nodes.
The diameter of a tree may or may not pass through the root.
Note: You can always assume that there are at least two leaf nodes in the given tree.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern08_tree_depth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;

int find_depth(TreeNode* node, int& diameter) {
	if (!node) return 0;
	int left_depth = find_depth(node->left, diameter);
	int right_depth = find_depth(node->right, diameter);
	diameter = max(diameter, left_depth+right_depth+1);

	return max(left_depth, right_depth)+1;
}

static int solver(TreeNode* root) {
	int diameter = 0;
	find_depth(root, diameter);
	return diameter;
}

void tree_diameter() {
	/*      1
		  /  \
		 2    3
		/   /   \
	   4   5     6    
	      /\    /    
		 7 8   9   
		   /   /
		  10  11      */
	TreeNode root(1);
	root.left = &TreeNode(2);
	root.right = &TreeNode(3);
	root.left->left = &TreeNode(4);
	root.right->left = &TreeNode(5);
	root.right->right = &TreeNode(6);
	

	root.left->left = nullptr;
	root.right->left->left = &TreeNode(7);
	root.right->left->right = &TreeNode(8);
	root.right->right->left = &TreeNode(9);
	root.right->left->right->left = &TreeNode(10);
	root.right->right->left->left = &TreeNode(11);

	int ans = solver(&root);


	cout << ans << endl;

	system("pause");

}