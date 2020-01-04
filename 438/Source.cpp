#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	using Map = unordered_map<char, int>;
	static void find_from(const string& s, const Map& map, size_t p_size, vector<int>& result)
	{
		auto s_size = s.size();
		if (p_size > s_size) return;
		auto curr_map = map;
		for (size_t i = 0; i < p_size; i++)
			remove(s[i], curr_map);
		if (curr_map.size() == 0) result.push_back(0);
		for (size_t i = 0; i + p_size < s_size; i++)
		{
			add(s[i], curr_map);
			remove(s[i + p_size], curr_map);
			if (curr_map.size() == 0) result.push_back(i+1);
		}
	}

	static void add(char c, Map& map)
	{
		if (map.count(c) == 0)
			map[c] = 1;
		else
		{
			map.at(c)++;
			if (map.at(c) == 0) map.erase(c);
		}
	}

	static void remove(char c, Map& map)
	{
		if (map.count(c) == 0)
			map[c] = -1;
		else
		{
			map.at(c)--;
			if (map.at(c) == 0) map.erase(c);
		}
	}

public:
	vector<int> findAnagrams(string s, string p)
	{
		vector<int> result;
		Map map;
		for (auto c : p)
			if (map.count(c) == 0)
				map[c] = 1;
			else map.at(c)++;
		find_from(s, map, p.size(), result);
		return result;
	}
};

void test(string s, string p)
{
	cout << "Input: s: " << s << " p: " << p << endl;
	Solution so;
	cout << "Output: " << so.findAnagrams(s, p) << endl;
}

int main()
{
	test("cbaebabacd", "abc");
	test("abab", "ab");
}