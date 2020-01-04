#include <unordered_map>

using namespace std;

struct trie
{
	char prefix;
	unordered_map<char,trie> children;
	trie() :prefix('*') {}
	trie(char c) :prefix(c) {}
	void insert(const string& str, size_t index = 0)	
	{
		if (index == str.size()) return;
		char c = str[index];
		if (children.count(c) == 0)
			children[c] = trie(c);
		children.at(c).insert(str, index + 1);
	}
};

class Solution
{
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
	{
		trie dic;
		for (auto word : words)
			dic.insert(word);
	}
};