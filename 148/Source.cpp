#include "../leetcode_misc/listcode_misc.h"
#include <iostream>


using namespace std;

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
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) {
			return head;
		}
		ListNode *slow = head, *fast = head->next;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *r = slow->next;
		slow->next = NULL;
		return merge(sortList(head), sortList(r));
	}
private:
	ListNode* merge(ListNode* l, ListNode* r) {
		if (!l || !r) {
			return l ? l : r;
		}
		if (l->val < r->val) {
			l->next = merge(l->next, r);
			return l;
		}
		r->next = merge(l, r->next);
		return r;
	}
};


void test(ListNode* head)
{
	Solution s;
	cout
		<< "input: " << endl
		<< head << endl;
	cout
		<< "output: " << s.sortList(head) << endl;
	delete head;
}

int main()
{
	test(LinkList({ 4,2,1,3 }));
	test(LinkList({ -1,5,3,4,0 }));
};
