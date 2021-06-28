/* Medium
Given a binary tree and a number ¡®S¡¯,
find all paths from root-to-leaf such that the sum of all the node values of each path equals ¡®S¡¯.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern07_tree_breadth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;

void find_path(TreeNode* node, int sum, vector<int>& cur_path, vector<vector<int>>& all_paths) {
	if (!node) return;

	cur_path.push_back(node->val);

	if (!node->left && !node->right && sum == node->val) {
		all_paths.push_back(cur_path);
	}
	else {
		find_path(node->left, sum-node->val, cur_path, all_paths);
		find_path(node->right, sum-node->val, cur_path, all_paths);
	}

	cur_path.pop_back();
}

static vector<vector<int>> solver(TreeNode* root, int sum) {
	vector<int> possible_path;
	vector<vector<int>> all_paths;
	find_path(root, sum, possible_path, all_paths);
	return all_paths;
}

void all_paths_for_a_sum() {
	/*     12
		  /  \
		 7    1
		/    / \
	   4    10  5     */
	TreeNode root(12);
	root.left = &TreeNode(7);
	root.right = &TreeNode(1);
	root.right->left = &TreeNode(10);
	root.right->right = &TreeNode(5);

	root.left->left = &TreeNode(4);
	//root.left->left->left = &TreeNode(3);

	vector<vector<int>> ans = solver(&root, 23);


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