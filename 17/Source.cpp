#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> r;
		if (digits == "") return r;
		list<string> container;
		for (auto c : monoid(digits.front()))
			container.push_back(string(1, c));
		for (size_t i = 1; i < digits.size(); i++)
		{
			auto m = monoid(digits[i]);
			list<string> buffer;
			for (auto c : m)
			{
				auto instance = append_all(container, c);
				buffer.splice(buffer.end(), instance);
			}
			container = buffer;
		}
		for (auto str : container)
			r.push_back(str);
		return r;
	}

private:
	static string monoid(char digit)
	{
		switch (digit)
		{
		case '2':
			return "abc";
		case '3':
			return "def";
		case '4':
			return "ghi";
		case '5':
			return "jkl";
		case '6':
			return "mno";
		case '7':
			return "pqrs";
		case '8':
			return "tuv";
		case '9':
			return "wxyz";
		}
	}
	static list<string> append_all(const list<string>& v, char c) {
		list<string> k;
		for (auto str : v)
			k.push_back(str + c);
		return k;
	}
};

void display(vector<string> vs)
{
	if (vs.size() == 0)
	{
		cout << "[]" << endl;
		return;
	}

	cout << "[" << vs.front();
	for (size_t i = 2; i < vs.size(); i++)
		cout << ", " << vs[i];
	cout << "]"<<endl;
}

void test(string str)
{
	Solution s;
	auto r = s.letterCombinations(str);
	display(r);
}

size_t main()
{
	test("23");
}