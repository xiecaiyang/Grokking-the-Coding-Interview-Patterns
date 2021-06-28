#include "TreeNode.hpp"
#include <iostream>
using namespace std;

void TreeNodeSuccessor::print_level_order() {
	TreeNodeSuccessor* next_level_root = this;
	while (next_level_root) {
		TreeNodeSuccessor* curNode = next_level_root;
		next_level_root = nullptr;
		while (curNode) {
			if (!next_level_root) {
				if (curNode->left) next_level_root = curNode->left;
				else if (curNode->right) next_level_root = curNode->right;
			}
			cout << curNode->val << ' ';
			curNode = curNode->next;
		}
		cout << endl;
	}
}

void TreeNodeSuccessor::print_all_order() {
	TreeNodeSuccessor* curNode = this;
	while (curNode) {
		cout << curNode->val << ' ';
		curNode = curNode->next;
	}
	cout << endl;
}