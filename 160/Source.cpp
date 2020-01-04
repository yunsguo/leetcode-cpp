#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
	size_t val;
	ListNode *next;
	ListNode(size_t x) : val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		auto la = length(headA);
		auto lb = length(headB);
		if (la >= lb) return left_first(headA, headB, la - lb);
		return left_first(headB, headA, lb - la);
	}

	ListNode *left_first(ListNode *left, ListNode *right, size_t step) {
		while (step != 0) {
			left = left->next;
			step--;
		}
		while (left != right) {
			left = left->next;
			right = right->next;
		}
		return left;
	}

	size_t length(ListNode *head) {
		if (head == nullptr) return 0;
		return 1 + length(head->next);
	}
};