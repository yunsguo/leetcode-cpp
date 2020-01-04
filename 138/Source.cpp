#include <unordered_map>

// Definition for a Node.
class Node
{
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random)
	{
		val = _val;
		next = _next;
		random = _random;
	}
};

using namespace std;

//class Solution {
//
//	static Node* crlIMPL(Node* node, unordered_map<Node*, Node*>& table)
//	{
//		if (node == nullptr) return node;
//		if (table.count(node) != 0)
//			return table.at(node);
//		auto curr = new Node();
//		table[node] = curr;
//		curr->val = node->val;
//		curr->next = crlIMPL(node->next, table);
//		curr->random = crlIMPL(node->random, table);
//		return node;
//	}
//
//public:
//	Node* copyRandomList(Node* head) {
//		unordered_map<Node*, Node*> table;
//		return crlIMPL(head, table);
//	}
//};

class Solution
{
	static Node* list_division(Node* node)
	{
		auto curr = new Node();
		curr->val = node->val;
		curr->random = node->random;
		curr->next = node->next;
		node->next = curr;
		return curr->next;
	}

	static Node* straightening_random(Node* node)
	{
		auto curr = node->next;
		if (curr->random != nullptr)
			curr->random = curr->random->next;
		return curr->next;
	}

	static Node* unweave(Node* node)
	{
		auto curr = node->next;
		node->next = curr->next;
		if (curr->next != nullptr)
			curr->next = curr->next->next;
		return node->next;
	}

	template<typename F>
	static void cycle(Node* node,F f)
	{
		Node* curr = node;
		while (curr != nullptr)
			curr = f(curr);
	}

public:
	Node* copyRandomList(Node* head)
	{
		if (head == nullptr) return nullptr;
		cycle(head, list_division);
		cycle(head, straightening_random);
		Node* result = head->next;
		cycle(head, unweave);
		return result;
	}
};
