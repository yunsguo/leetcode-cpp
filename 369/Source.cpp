#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using ListNode = ListNodeOf<int>;
using namespace std;
class Solution
{
	static bool plus_one_impl(ListNode* head)
	{
		if (head->next == nullptr || plus_one_impl(head->next))
			return inc(head->val);
		return false;
	}

	static bool inc(int& val)
	{
		if (val != 9)
		{
			val++; return false;
		}
		val = 0; return true;
	}

public:
	ListNode* plusOne(ListNode* head)
	{
		if (head == nullptr) return nullptr;
		if (plus_one_impl(head))
		{
			auto new_head = new ListNode(1);
			new_head->next = head;
			return new_head;
		}
		return head;
	}
};

void test(initializer_list<int> l)
{
	auto head = LinkList<int>(l);
	Solution s;
	cout << "Input: " << head << endl;
	cout << "Output: " << s.plusOne(head) << endl;
}

int main()
{
	test({1,2,3});
	test({ 9,9,9 });
	test({ 1,0,9 });
}