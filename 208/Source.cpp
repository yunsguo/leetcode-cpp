#include <string>
#include <iostream>

using namespace std;

class Trie
{
	constexpr const static size_t number_of_letter = 26;

	struct trie
	{
		bool is_terminal;
		trie* children[number_of_letter];
		trie() :is_terminal(false)
		{
			for (size_t i = 0; i < number_of_letter; i++)
				children[i] = nullptr;
		}

		~trie()
		{
			for (size_t i = 0; i < number_of_letter; i++)
			{
				delete children[i];
				children[i] = nullptr;
			}
		}
	};

	trie* root;

	static void insert(trie* t, const string& str, size_t pos)
	{
		auto& child = t->children[str[pos] - 'a'];
		if (child == nullptr)child = new trie();
		if (pos + 1 == str.size())
		{
			child->is_terminal = true;
			return;
		}
		insert(child, str, pos + 1);
	}

	static bool search(trie* t, const string& str, size_t pos)
	{
		auto child = t->children[str[pos] - 'a'];
		if (child == nullptr) return false;
		if (pos + 1 == str.size()) return child->is_terminal;
		return search(child, str, pos + 1);
	}

	static bool start_with(trie* t, const string& str, size_t pos)
	{
		auto child = t->children[str[pos] - 'a'];
		if (child == nullptr) return false;
		if (pos + 1 == str.size()) return true;
		return start_with(child, str, pos + 1);
	}

public:
	/** Initialize your data structure here. */
	Trie() :root(new trie()) {}

	/** Inserts a word into the trie. */
	void insert(string word)
	{
		insert(root, word, 0);
	}

	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		return search(root, word, 0);
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix)
	{
		return start_with(root, prefix, 0);
	}

	~Trie()
	{
		delete root;
		root = nullptr;
	}
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
	Trie trie;
	trie.insert("apple");
	cout << trie.search("apple") << endl;   // returns true
	cout << trie.search("app") << endl;     // returns false
	cout << trie.startsWith("app") << endl; // returns true
	trie.insert("app");
	cout << trie.search("app") << endl;;     // returns true
}