#include <vector>
#include <string>
#include <list>
#include <iostream>

using namespace std;

template<typename T>
ostream & operator <<(ostream& out, const list<T>& list)
{
	out << "[";
	if (!list.empty())
	{
		auto itor = list.cbegin();
		out << *itor;
		itor++;
		while (itor != list.cend())
		{
			out << ", " << *itor;
			itor++;
		}
	}
	out << "]";
	return out;
}

template<typename T>
ostream & operator <<(ostream& out, const vector<T>& vector)
{
	out << "[";
	if (!vector.empty())
	{
		auto itor = vector.cbegin();
		out << *itor;
		itor++;
		while (itor != vector.cend())
		{
			out << ", " << *itor;
			itor++;
		}
	}
	out << "]";
	return out;
}


class Solution 
{
public:
	vector<vector<string>> res;

	void f(int i, vector<vector<bool>>& dp, vector<string>& cur, string& s) {

		int n = s.length();

		if (i == n) {
			res.push_back(cur);
			return;
		}

		for (int j = i; j < n; j++)
			if (dp[i][j]) {
				cur.push_back(s.substr(i, j - i + 1));
				f(j + 1, dp, cur, s);
				cur.pop_back();
			}
	}

	vector<vector<string>> partition(string s) {

		int n = s.length();
		res.clear();

		vector<vector<bool>> dp(n, vector<bool>(n, 0));

		for (int i = 0; i < n; i++)
			dp[i][i] = true;

		for (int l = 1; l < n; l++) {

			for (int i = 0, j = i + l; j < n; i++, j++) {

				if (s[i] == s[j]) {

					if (l == 1) dp[i][j] = 1;

					else dp[i][j] = dp[i + 1][j - 1];

				}
			}
		}

		vector<string> temp;
		f(0, dp, temp, s);
		return res;
	}
};

//class Solution
//{
//	static void merge(list<list<string>>& v1, list<list<string>>& v2)
//	{
//		v1.splice(v1.end(), v2);
//	}
//
//public:
//	vector<vector<string>> partition(string s)
//	{
//		list<list<string>> result;
//		full_partition(s, result);
//		vector<vector<string>> converted;
//		for (auto& ss : result)
//			converted.push_back(vector<string>(std::make_move_iterator(std::begin(ss)),
//				std::make_move_iterator(std::end(ss))));
//		return converted;
//	}
//
//private:
//
//	static bool is_palindrome(const string& str)
//	{
//		for (size_t i = 0; i < str.size() / 2; i++)
//			if (str[i] != str[str.size() - i - 1]) return false;
//		return true;
//	}
//
//	static void full_partition(string str, list<list<string>>& result)
//	{
//		if (str.size() == 0)
//			return;
//		result.push_back({ string(1,str[0]) });
//		for (size_t i = 1; i + 1 < str.size(); i++)
//		{
//			char c = str[i];
//			list<list<string>> merge_result(result);
//			map_add(c, result);
//			map_merge(c, merge_result);
//			merge(result, merge_result);
//		}
//		if (str.size() == 1) return;
//		char last = str.back();
//		list<list<string>> merge_result(result);
//		map_add(last, result);
//		map_merge_last(last, merge_result);
//		merge(result, merge_result);
//	}
//
//	static void map_add(char c, list<list<string>>& sss)
//	{
//		string cs(1, c);
//		auto i = sss.begin();
//		while (i != sss.end())
//		{
//			if (is_palindrome(i->back()))
//			{
//				i->push_back(cs);
//				i++;
//			}
//			else
//				i = sss.erase(i);
//		}
//	}
//
//	static void map_merge(char c, list<list<string>>& sss)
//	{
//		auto i = sss.begin();
//		while (i != sss.end())
//		{
//			if (i->size() > 1 && !is_palindrome(*++i->rbegin()))
//				i = sss.erase(i);
//			else
//			{
//				i->back().push_back(c);
//				i++;
//			}
//		}
//	}
//
//	static void map_merge_last(char c, list<list<string>>& sss)
//	{
//		auto i = sss.begin();
//		while (i != sss.end())
//		{
//			i->back().push_back(c);
//			if (!is_palindrome(i->back()))
//				i = sss.erase(i);
//			else i++;
//		}
//	}
//
//};


int main()
{
	Solution s;
	string str = "a";
	cout << "input: " << str << endl;
	cout << "output: " << s.partition(str) << endl;
};
