#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include <queue>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

struct trie
{
	char prefix;
	trie* next;
	trie* child;
	trie() :prefix('*'), next(nullptr), child(nullptr) {}
	trie(char c) :prefix(c), next(nullptr), child(nullptr) {}
	bool insert(const string& str, size_t index = 0)
	{
		if (index == str.size()) return true;
		if (str.at(index) == prefix)
		{
			if (next != nullptr) return false;
			if (index + 1 == str.size()) return true;
			if (child == nullptr)child = new trie(str.at(index + 1));
			return child->insert(str, index + 1);
		}
		if (next == nullptr)next = new trie(str.at(index));
		return next->insert(str, index);
	}
};

class Solution
{
	static void construct_edges(const string& seg, unordered_map<char, unordered_set<char>>& edges, size_t i = 0)
	{
		if (i >= seg.size()) return;
		auto larger = seg[i];
		for (size_t j = i + 1; j < seg.size(); j++)
		{
			if (edges.count(larger) == 0)
				edges[larger] = unordered_set<char>();
			edges.at(larger).insert(seg[j]);
		}
	}
	static bool collect_list(trie* t, unordered_map<char, unordered_set<char>>& edges, unordered_set<char>& set)
	{
		if (set.count(t->prefix) != 0)
			return false;
		set.insert(t->prefix);
		string seg = "";
		auto curr = t;
		seg += curr->prefix;
		while (curr->next != nullptr)
		{
			curr = curr->next;
			seg += curr->prefix;
			if (!collect(curr->child, edges, set)) return false;
		}
		construct_edges(seg, edges);
		return true;
	}

	static bool collect(trie* t, unordered_map<char, unordered_set<char>>& edges, unordered_set<char>& set)
	{
		if (t == nullptr) return true;
		set.insert(t->prefix);
		if (t->next != nullptr)
			return collect_list(t, edges, set);
		return collect(t->child, edges, set);
	}

	static bool has_loop(unordered_map<char, unordered_set<char>>& edges)
	{
		unordered_set<char> visited;
		vector<char> queue;
		if (edges.size() == 0) return false;
		auto pair = *edges.cbegin();
		visited.insert(pair.first);
		for (auto index : pair.second)
			queue.push_back(index);
		while (queue.size() != 0)
		{
			auto node = queue.back();
			queue.pop_back();
			if (visited.count(node) != 0) return true;
			visited.insert(node);
			if (edges.count(node) != 0)
				for (auto child : edges.at(node))
					queue.push_back(child);
		}
		return false;
	}

	static void construct_anti_edges(const unordered_map<char, unordered_set<char>>& edges, unordered_map<char, unordered_set<char>>& aedges)
	{
		for (auto pair : edges)
		{
			for (auto smaller : pair.second)
			{
				if (aedges.count(smaller) == 0)
					aedges[smaller] = unordered_set<char>();
				aedges.at(smaller).insert(pair.first);
			}
		}
	}

	static void topological_sort(string& L, unordered_set<char>& S, unordered_map<char, unordered_set<char>>& edges, unordered_map<char, unordered_set<char>>& anti_edges)
	{
		while (S.size() != 0)
		{
			auto n = *S.begin();
			S.erase(n);
			L += n;
			if (edges.count(n) != 0)
			{
				auto &es = edges.at(n);
				while (es.size() != 0)
				{
					auto m = *es.begin();
					es.erase(m);
					anti_edges.at(m).erase(n);
					if (anti_edges.count(m) == 0 || anti_edges.at(m).size() == 0)
						S.insert(m);
				}
			}
		}
	}

public:
	string alienOrder(vector<string>& words)
	{
		trie root;
		for (const auto& word : words)
			if (!root.insert(word)) return "";
		unordered_map<char, unordered_set<char>> edges;
		unordered_map<char, unordered_set<char>> anti_edges;
		unordered_set<char> set;
		cout << "collect successful: " << collect(root.child, edges, set) << endl;
		string result = "";
		if (has_loop(edges)) return result;
		construct_anti_edges(edges, anti_edges);
		unordered_set<char> largest_nodes;
		for (auto c : set)
			if (anti_edges.count(c) == 0)
				largest_nodes.insert(c);
		cout << "S: " << largest_nodes << endl;
		cout << "Edges: " << edges << endl;
		cout << "Anti-edges: " << anti_edges << endl;
		topological_sort(result, largest_nodes, edges, anti_edges);
		return result;
	}
};

void test(vector<string> str)
{
	cout << "Input: " << str << endl;
	Solution s;
	cout << "Output: " << s.alienOrder(str) << endl;
}

int main()
{
	test({ "wrt","wrf","er","ett","rftt" });
	test({ "z","x" });
	test({ "z","x","z" });
	test({ "z","z" });
	test({ "zy","zx" });
	test({ "aa", "abb", "aba" });
}