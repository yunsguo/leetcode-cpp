#include <iostream>
#include <vector>
#include "../leetcode_misc/listcode_misc.h"
#include <string>

using namespace std;


class Solution {
public:
	bool isMatch(string s, string p)
	{
		if (p == "")
		{
			if (s == "") return true;
			return false;
		}
		vector<string> ps;
		string b_p = "";
		string e_p = "";
		size_t start = 0;
		if (p.front() != '*')
			b_p = split(p, start);

		while (true)
		{
			auto seg = split(p, start);
			if (seg == "") break;
			ps.push_back(seg);
		}
		if (p.back() != '*' && ps.size() >= 1)
		{
			e_p = ps.back();
			ps.pop_back();
		}
		start = 0;
		if (b_p != "")
			if (!match_begin(s, start, b_p)) return false;

		for (size_t i = 0; i < ps.size(); i++)
			if (!try_match(s, start, ps[i]))
				return false;
		if (e_p == "") {
			if (start < s.size() && p.back() != '*') return false;
			return true;
		}
		return match_end(s, start, e_p);
	}

private:
	static string split(const string& str, size_t& start)
	{
		while (start < str.size() && str[start] == '*')
			start++;
		auto end = start;
		while (end < str.size() && str[end] != '*')
			end++;
		auto r = str.substr(start, end - start);
		start = end;
		return r;
	}

	static bool match_begin(const string& str, size_t& start, const string& pattern)
	{
		if (str.size() < pattern.size())
			return false;
		for (size_t i = 0; i < pattern.size(); i++)
			if (str[i] != pattern[i] && pattern[i] != '?')
				return false;
		start += pattern.size();
		return true;
	}

	static bool match_end(const string& str, size_t& start, const string& pattern)
	{
		if (str.size() - start < pattern.size())
			return false;
		size_t offset = str.size() - pattern.size();
		for (size_t i = 0; i < pattern.size(); i++)
			if (str[offset + i] != pattern[i] && pattern[i] != '?')
				return false;
		return true;
	}

	static bool try_match(const string& str, size_t& start, const string& pattern)
	{
		if (pattern.front() != '?')
		{
			while (start < str.size() && str[start] != pattern.front())
				start++;
			if (start >= str.size())
				return false;
		}
		if (start >= str.size() || str.size() - start < pattern.size()) return false;
		for (size_t i = 0; i < pattern.size(); i++)
			if (str[i + start] != pattern[i] && pattern[i] != '?')
			{
				start++;
				return try_match(str, start, pattern);
			}
		start += pattern.size();
		return true;
	}
};

void test(string s, string p)
{
	Solution so;
	cout
		<< "Input: " << endl
		<< "s = \"" << s << "\"" << endl
		<< "p = \"" << p << "\"" << endl;
	cout << "Output: " << (so.isMatch(s, p) ? "true" : "false") << endl << endl;
}

int main()
{
	test("aa", "a");
	test("aa", "aa");
	test("hi", "*?");
	test("aa", "*");
	test("b", "*?*?");
	test("b", "*a*");
	test("ho", "ho**");
	test("aaaa", "***a");
	test("bbba","*a?a*");
	test("acdcb", "a*c?b");
	test("adceb", "*a*b");
	test("mississippi", "m??*ss*?i*pi");
	test("mississippi", "m*issip*");
	test("abefcdgiescdfimde", "ab*cd?i*de");
	test("baabbababaaaaaaaabbbbb", "**ab***bb");
	test("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b");
	test("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb");

}