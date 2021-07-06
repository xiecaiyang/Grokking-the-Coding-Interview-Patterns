/* Medium
Given a binary tree and a number sequence, find if the sequence is present as a root-to-leaf path in the given tree.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern07_tree_breadth_first_search.hpp"
#include "TreeNode.hpp"
using namespace std;

bool check_seq(TreeNode* node, int pos, vector<int>& seq) {
	if (pos>=seq.size()) {
		return node ? false : true;
	}
	else {
		if (!node) return false;
		if (seq[pos] == node->val) {
			return check_seq(node->left,pos+1,seq) || check_seq(node->right, pos+1, seq);
		}
		else
			return false;
	}
}

static bool solver(TreeNode* root, vector<int> seq) {
	
	return check_seq(root, 0, seq);
}

void path_with_given_sequence() {
	/*     1
		  / \
		 0   1
		/   / \
	   1   6   5     */
	TreeNode root(1);
	root.left = &TreeNode(0);
	root.right = &TreeNode(1);
	root.left->left = &TreeNode(1);
	root.right->left = &TreeNode(6);
	root.right->right = &TreeNode(5);

	vector<int> seq{1,2,4};

	bool ans = solver(&root, seq);



	cout << ans << endl;

	system("pause");

}