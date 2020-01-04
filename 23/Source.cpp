#include <vector>
#include <forward_list>
#include <iostream>
#include <string>
#include "../leetcode_misc/listcode_misc.h"
#include <list>

using namespace std;

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		discard_empty(lists);
		if (lists.size() == 0) return nullptr;
		if (lists.size() == 1) return lists.front();

		quick_sort(lists, 0, lists.size() - 1);
		auto head = lists.front();
		auto finger = head;
		while (true)
		{
			lists.front() = lists.front()->next;
			insert(lists);
			if (lists.size() == 0) break;
			finger->next = lists[0];
			finger = finger->next;
		}
		return head;
	}

	void discard_empty(vector<ListNode*>& lists)
	{
		while (lists.size()!=0 && lists.back() == nullptr) lists.pop_back();

		size_t i = 0;
		while (i < lists.size())
		{
			if (lists[i] == nullptr)
			{
				lists[i] = lists.back();
				lists.pop_back();
			}
			else i++;
		}
	}

	void insert(vector<ListNode*>& A)
	{
		if (A.front() == nullptr)
		{
			A.erase(A.begin());
			return;
		}

		size_t i = 0;
		for (size_t j = 1; j < A.size(); j++)
			if (A[i]->val >= A[j]->val)
			{
				swap(A[i], A[j]);
				i = j;
			}
	}

	ListNode* initial_sort(vector<ListNode*>& lists)
	{
		quick_sort(lists, 0, lists.size() - 1);
		return lists.front();
	}

	void quick_sort(vector<ListNode*>& A, size_t lo, size_t hi)
	{
		if (lo < hi)
		{
			auto p = partition(A, lo, hi);
			quick_sort(A, lo, p - 1);
			quick_sort(A, p + 1, hi);
		}
	}

	size_t partition(vector<ListNode*>& A, size_t lo, size_t hi)
	{
		auto pivot = A[hi]->val;
		auto i = lo;
		for (size_t j = lo; j < hi; j++)
			if (A[j]->val < pivot)
			{
				swap(A[i], A[j]);
				i++;
			}
		swap(A[i], A[hi]);
		return i;
	}
};

void test(vector<ListNode*> v)
{
	Solution s;
	cout << "Input: " << v << endl;
	auto r = s.mergeKLists(v);
	cout << "Output: " << r << endl << endl;
}
size_t main()
{
	test({ LinkList({1,4,5}),LinkList({1,3,4}),LinkList({2,6}) });
	test({ LinkList({}),LinkList({})});
}