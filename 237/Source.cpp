#include "../leetcode_misc/listcode_misc.h"

using namespace std;
using ListNode = ListNodeOf<int>;

class Solution 
{
public:
	void deleteNode(ListNode* node) 
	{
		{
			while (node->next->next!=nullptr)
			{
				node->val = node->next->val;
				node = node->next;
			}
			node->val = node->next->val;
			delete node->next;
			node->next = nullptr;
		}
	}
};