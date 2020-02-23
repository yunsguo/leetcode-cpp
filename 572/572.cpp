// 572.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include "../util/util.h"
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

using TreeNode = TreeNodeOf<int>;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isSubset(TreeNode* s, TreeNode* t) {
		if (t == nullptr) return true;
		if (s == nullptr) return false;
		if (s->val != t->val) return false;
		return isSubset(s->left, t->left) && isSubset(s->right, t->right);
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (t == nullptr) return true;
		if (s == nullptr) return false;
		return isSubset(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
	}
};
int main()
{
	std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
