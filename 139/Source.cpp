#include <vector>
#include <iostream>
#include <string>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	static bool breakable(const string& word, const string& entry, size_t start = 0)
	{
		if (entry.size() + start > word.size())
			return false;
		for (size_t i = 0; i < entry.size(); i++)
			if (word[i + start] != entry[i]) return false;
		return true;
	}

public:
	bool wordBreak(string s, vector<string>& wordDict)
	{
		vector<bool> table(s.size() + 1, false);
		for (auto entry : wordDict)
			if (breakable(s, entry))
				table[entry.size()] = true;

		for (size_t i = 0; i < table.size(); i++)
			if (table[i])
				for (auto entry : wordDict)
					if (breakable(s, entry, i))
						table[entry.size() + i] = true;
		return table.back();
	}


};

void test(string word, vector<string> dict)
{
	Solution s;
	cout
		<< "input: " << endl
		<< "word:  " << word << endl
		<< "dictionary: " << dict << endl
		<< "output: " << s.wordBreak(word, dict) << endl;
}

int main()
{
	test("leetcode", { "leet","code" });
	test("applepenapple", { "apple", "pen" });
	test("catsandog", { "cats", "dog", "sand", "and", "cat" });
	test("abcd", { "a", "abc", "b", "cd" });
	test("aaaaaaa", { "aaaa","aa" });
	test("dcacbcadcad", { "cbd", "dca", "bcdc", "dcac", "ad" });
	test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" });
	test("goalspecial", { "go", "goal", "goals", "special" });
};
