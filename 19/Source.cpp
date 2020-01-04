#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

struct ListNode {
	size_t val;
	ListNode *next;
	ListNode(size_t x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, size_t n) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		size_t length;
		rnfe_impl(dummy, n, 0, length);
		return dummy->next;
	}

	size_t rnfe_impl(ListNode* curr, size_t n, size_t index, size_t& length) {
		size_t back_index;
		if (curr->next->next != nullptr)
			back_index = rnfe_impl(curr->next, n, index + 1, length) + 1;
		else
		{
			length = index + 2;
			back_index = 1;
		}

		if (back_index == n)
		{
			auto next = curr->next->next;
			delete curr->next;
			curr->next = next;
		}
		return back_index;

	}
};

size_t main()
{

}