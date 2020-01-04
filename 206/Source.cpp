#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;


struct ListNode {
     size_t val;
     ListNode *next;
     ListNode(size_t x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		auto* finger = head;
		if (finger == nullptr) return finger;
		while (finger->next != nullptr)
			finger = finger->next;
		reverse(head, nullptr);
		return finger;
	}

	void reverse(ListNode* curr, ListNode* prev)
	{
		if (curr == nullptr) return;
		reverse(curr->next,curr);
		curr->next = prev;
	}
};