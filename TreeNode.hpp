#pragma once
#ifndef _TREENODE_
#define _TREENODE_

class TreeNode {
private:

public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() {
		val = 0;
		left, right = nullptr;
	}
	TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TreeNodeSuccessor {
public:
	int val;
	TreeNodeSuccessor* left;
	TreeNodeSuccessor* right;
	TreeNodeSuccessor* next;

	TreeNodeSuccessor() : val(0), next(nullptr) {}
	TreeNodeSuccessor(int value) : val(value), left(nullptr), right(nullptr), next(nullptr) {}
	TreeNodeSuccessor(int value, TreeNodeSuccessor* a, TreeNodeSuccessor* b, TreeNodeSuccessor* c) : val(value), left(a), right(b), next(c) {}

	void print_level_order();
	void print_all_order();
};
#endif