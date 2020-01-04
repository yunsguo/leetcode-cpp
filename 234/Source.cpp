#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

using ListNode = ListNodeOf<int>;

class Solution
{
	static pair<size_t, ListNode*> fetch_half_and_size(ListNode* head)
	{
		size_t length = 1;
		auto curr = head;
		auto half = head;
		while (curr->next != nullptr)
		{
			length++;
			curr = curr->next;
			if (length % 2 == 1)
				half = half->next;
		}
		return { length,half };
	}
	static pair<bool, ListNode*> recursive_check(ListNode* head, size_t length)
	{
		if (length == 1) return { true,head->next };
		if (length == 2) return { head->val == head->next->val,head->next->next };
		auto next = recursive_check(head->next, length - 2);
		if (!next.first || head->val != next.second->val) return { false,nullptr };
		return { true,next.second->next };
	}

	static bool first_kth_equal(ListNode* h1, ListNode* h2, size_t k)
	{
		for (size_t i = 1; i <= k; i++)
		{
			if (h1->val != h2->val) return false;
			h1 = h1->next;
			h2 = h2->next;
		}
		return true;
	}

	static ListNode* reverse(ListNode* node)
	{
		if (node == nullptr) return nullptr;
		auto result = node;
		ListNode* prev = nullptr;
		while (true)
		{
			auto next = result->next;
			result->next = prev;
			prev = result;
			if (next != nullptr)
				result = next;
			else break;
		}
		return result;
	}


public:
	bool isPalindrome(ListNode* head)
	{
		if (head == nullptr) return false;
		auto pair = fetch_half_and_size(head);
		if (pair.first == 1) return true;
		return first_kth_equal(head, reverse(pair.second->next), pair.first / 2);
	}
};

void test(initializer_list<int> list)
{
	auto head = LinkList(list);
	cout << "Input: " << head << endl;
	Solution s;
	cout << "Output: " << (s.isPalindrome(head) ? "True" : "False") << endl;
}

int main()
{
	test({ 1,2 });
	test({ 1,2,2,1 });
	test({ 1,2,3,2,1 });
	test({ 1,2,4 });
}