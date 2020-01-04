#pragma once
#ifndef MISC
#define MISC
#include <initializer_list>

template<typename V>
struct TreeNodeOf
{
	V val;
	TreeNodeOf *left;
	TreeNodeOf *right;
	TreeNodeOf(V x) : val(x), left(nullptr), right(nullptr) {}
};

//template<typename V>
//class nullable
//{
//	std::optional<V> val;
//public:
//	nullable(V arg) :val(arg) {}
//	nullable(std::nullptr_t nptr) :val() {}
//	bool has_value() { return val.has_value(); }
//	V value() { return val.value(); }
//};

//template<typename V>
//TreeNodeOf<V>* BinaryTree(const vector<nullable<V>>& l, size_t offset = 0)
//{
//	if (offset >= l.size() || !l[offset].has_value()) return nullptr;
//	auto node = new TreeNodeOf<V>(l[offset]);
//	node->left = BinaryTree(l, offset * 2 + 1);
//	node->right = BinaryTree(l, offset * 2 + 2);
//	return node;
//}

template<typename V>
struct ListNodeOf
{
	V val;
	ListNodeOf *next;
	ListNodeOf(V x) :val(x), next(nullptr) {}
	~ListNodeOf() { delete next; next = nullptr; }
};

template<typename V>
ListNodeOf<V>* LinkList(std::initializer_list<V> l)
{
	if (l.size() == 0)
		return nullptr;
	auto it = l.begin();
	auto head = new ListNodeOf<V>(*it);
	auto finger = head;
	it++;
	while (it != l.end())
	{
		finger->next = new ListNodeOf<V>(*it);
		finger = finger->next;
		it++;
	}
	return head;
}


struct Point
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	Point(std::initializer_list<int> l)
	{
		auto itor = l.begin();
		x = *itor;
		itor++;
		y = *itor;
	}
};

#endif // _IOSTREAM_