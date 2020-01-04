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
	bool hasCycle(ListNode *head) {
		if (head == nullptr) return false;
		unordered_set<ListNode*> table;
		table.insert(head);
		head = head->next;
		while (head != nullptr) {
			if (table.count(head) > 0) return true;
			table.insert(head);
			head = head->next;
		}
		return false;
	}
};

size_t main()
{								
	size_t a = (size_t)nullptr;
	for (size_t i = 3; i < 10; i++)
		a = a ^ i;
	a = a ^ 9;
	std::cout << a << std::endl;
}