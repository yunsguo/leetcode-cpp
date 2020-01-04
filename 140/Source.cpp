#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution {

	static bool breakable(const string& word, const string& entry, size_t start = 0)
	{
		if (entry.size() + start > word.size())
			return false;
		for (size_t i = 0; i < entry.size(); i++)
			if (word[i + start] != entry[i]) return false;
		return true;
	}

	static void list_comprehension(
		vector<vector<size_t>>& result
		, const vector<size_t>& curr
		, const unordered_map<size_t, vector<size_t>>& map)
	{
		if (curr.back() == 0)
		{
			result.push_back(curr);
			return;
		}
		auto options = map.at(curr.back());
		for (auto v : map.at(curr.back()))
		{
			vector<size_t> next(curr);
			next.push_back(v);
			list_comprehension(result, next, map);
		}
	}

	static void convert(vector<string>& container, const string& word, const vector<vector<size_t>>& result)
	{
		for (auto list : result)
			container.push_back(convert_str(list, word));
	}

	static string convert_str(const vector<size_t>& indices, const string& word)
	{
		string curr = "";
		size_t prev_i = indices.back();
		auto l = indices.size();
		auto curr_i = indices[l - 2];
		curr.append(word.substr(prev_i, curr_i - prev_i));
		prev_i = curr_i;
		for (size_t i = 2; i < l; i++)
		{
			curr_i = indices[l - i - 1];
			curr.append(" " + word.substr(prev_i, curr_i - prev_i));
			prev_i = curr_i;
		}
		return curr;
	}

public:

	vector<string> wordBreak(string s, vector<string>& wordDict)
	{
		unordered_map<size_t, vector<size_t>> options;

		vector<bool> table(s.size() + 1, false);
		table.front() = true;

		for (size_t i = 0; i < s.size(); i++)
			if (table[i])
				for (auto entry : wordDict)
					if (breakable(s, entry, i))
					{
						table[entry.size() + i] = true;
						options[entry.size() + i].push_back(i);
					}
		cout << "options: " << options << endl;
		if (!table.back())
			return {};
		vector<vector<size_t>> result;
		vector<size_t> first(1, table.size() - 1);
		list_comprehension(result, first, options);
		vector<string> return_val;
		convert(return_val, s, result);
		return return_val;
	}
};


void test(string word, vector<string> dict)
{
	Solution s;
	cout
		<< "input: " << endl
		<< "word:  " << word << endl
		<< "dictionary: " << dict << endl
		<< "output: " << s.wordBreak(word, dict) << endl << endl;
}

int main()
{
	test("leetcode", { "leet","code" });
	test("catsanddog", { "cat","cats", "and", "sand", "dog" });
	test("pineapplepenapple", { "apple", "pen", "applepen", "pine", "pineapple" });
	test("catsandog", { "cats", "dog", "sand", "and", "cat" });
};