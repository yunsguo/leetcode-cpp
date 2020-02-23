// 21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include "../leetcode_misc/listcode_misc.h"
#include "../util/util.h"

using ListNode = ListNodeOf<int>;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



class Solution {
	static ListNode* MTL_r(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		if (l1->val >= l2->val)
			return MTL_r(l2, l1);

		auto tail = l1->next;
		l1->next = MTL_r(tail, l2);
		return l1;
	}
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		return MTL_r(l1, l2);
	}
};
int main()
{
	std::cout << "Hello World!\n";
	cout << mergeTwoLists(LinkList({1,2,4})
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
