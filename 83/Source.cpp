#include <string>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct ListNode {
	size_t val;
	ListNode *next;
	ListNode(size_t x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		if (head == nullptr) return nullptr;
		if (head->next == nullptr) return head;
		if (head->val == head->next->val) return deleteDuplicates(head->next);
		auto x = new ListNode(head->val);
		x->next = deleteDuplicates(head->next);
		return x;
	}
};