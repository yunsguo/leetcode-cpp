#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct ListNode {
	size_t val;
	ListNode *next;
	ListNode(size_t x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, size_t val) {
		if (!head) return nullptr;
		if (head->next)
			head->next = removeElements(head->next, val);
		if (head->val != val) return head;
		return head->next;
	}
};