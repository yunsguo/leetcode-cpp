#include <iostream>
#include <vector>
#include "../leetcode_misc/listcode_misc.h"
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, vector<string>> table;
		for (auto str : strs)
		{
			auto sig = count(str);
			if (table.count(sig) == 0)
				table[sig] = { str };
			else table.at(sig).push_back(str);
		}
		vector<vector<string>> r;
		for (auto pair : table)
			r.push_back(pair.second);
		return r;
	}

private:
	static string count(const string& str)
	{
		map<char, size_t> table;
		for (auto c : str)
			if (table.count(c) == 0) table[c] = 1;
			else table.at(c)++;
		string r = "";
		for (auto pair : table)
		{
			r += pair.first;
			r += (char)pair.second % 256;
		}
		return r;
	}
};

void test(vector<string> nums)
{
	Solution so;
	cout << "Input: " << nums << endl;
	cout << "Output: " << so.groupAnagrams(nums) << endl << endl;
}

int main()
{
	test({ "eat", "tea", "tan", "ate", "nat", "bat" });
}