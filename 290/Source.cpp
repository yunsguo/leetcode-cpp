#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

	class Solution
	{
		static string token(string& str)
		{
			size_t i = str.find(' ');
			if (i == string::npos)
			{
				auto temp = str;
				str = "";
				return temp;
			}
			auto temp = str.substr(0, i);
			str = str.substr(i + 1);
			return temp;
		}

	public:

		bool wordPattern(string pattern, string str)
		{
			unordered_map<char, string> p_table;
			unordered_map<string, char> w_table;
			size_t N = pattern.size();
			for (size_t i = 0; i < N; i++)
			{
				auto p = pattern[i];
				auto t = token(str);
				if (t == "") return false;
				if (p_table.count(p) == 0 && w_table.count(t) == 0)
				{
					p_table[p] = t;
					w_table[t] = p;
				}
				else if (p_table.count(p) == 0 || w_table.count(t) == 0)
					return false;
				if (p_table.at(p) != t || w_table.at(t) != p) return false;
			}
			auto rest = token(str);
			if (rest != "") return false;
			return true;
		}
	}; 