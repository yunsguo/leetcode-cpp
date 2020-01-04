#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> morph_table;
		unordered_set<char> morphee;
		for (size_t i = 0; i < s.size(); i++)
			if (morph_table.count(s[i]) == 0)
			{
				if (morphee.count(t[i]) != 0) return false;
				morph_table[s[i]] = t[i];
				morphee.emplace(t[i]);
			}
			else if (morph_table.at(s[i]) != t[i]) return false;
		return true;
	}
};