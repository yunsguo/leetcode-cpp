#include <string> 
#include <iostream>
#include <unordered_map>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	using Map = unordered_map<char, int>;

	static void add(Map& map, const string& str)
	{
		for (auto c : str)
			if (map.count(c) == 0)
				map[c] = 1;
			else
			{
				map.at(c)++;
				if (map.at(c) == 0)map.erase(c);
			}
	}

	static void remove(Map& map, const string& str)
	{
		for (auto c : str)
			if (map.count(c) == 0)
				map[c] = -1;
			else
			{
				map.at(c)--;
				if (map.at(c) == 0)map.erase(c);
			}
	}
public:
	bool isAnagram(string s, string t)
	{
		if (s.size() != t.size()) return false;
		Map map;
		add(map, s);
		remove(map, t);
		return map.size() == 0;
	}
};

void test(string s, string t)
{
	cout << "Input: s = " << s << " t = " << t << endl;
	Solution so;
	cout << "Output: " << (so.isAnagram(s, t) ? "true" : "false") << endl;
}

int main()
{
	test("anagram", "nagaram");
	test("rat", "car");
}