#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
	using Integer = int;
	using map = unordered_map<Integer, Integer>;

	static Integer ftd_large(Integer n, Integer d, Integer&out)
	{
		out = n / d;
		return n % d;
	}

	static size_t ftd_impl(Integer n, Integer d, vector<Integer>& out, map& reverse_table)
	{
		n *= 10;
		while (n < d)
		{
			n *= 10;
			out.push_back(0);
		}
		auto q = n / d;
		auto r = n % d;
		if (reverse_table.count(q) != 0)
			return reverse_table.at(q);
		reverse_table[q] = out.size();
		out.push_back(q);
		if (r == 0) return -1;
		return ftd_impl(r, d, out, reverse_table);
	}





public:
	string fractionToDecimal(int numerator, int denominator)
	{
		Integer larger = 0;
		if (numerator >= denominator)
			numerator = ftd_large(numerator, denominator, larger);
		if (numerator == 0) return to_string(larger);
		map reverse_table;
		vector<Integer> repeat;
		auto requrring_po = ftd_impl(numerator, denominator, repeat, reverse_table);
		string the_rest;
		if (requrring_po != -1)
		{
			for (size_t i = 0; i < requrring_po; i++)
				the_rest += repeat[i] + '0';
			the_rest += '(';
			for (size_t i = requrring_po; i < repeat.size(); i++)
				the_rest += repeat[i] + '0';
			the_rest += ')';
		}
		else
			for (auto n : repeat)
				the_rest += n + '0';
		return to_string(neg*larger) + '.' + the_rest;
	}
};

void test(int numerator, int denminator)
{
	cout << "Input: " << numerator << ", " << denminator << endl;
	Solution s;
	cout << "Output: " << s.fractionToDecimal(numerator, denminator) << endl;
}

int main()
{
	cout << -1 % 2 << endl;
	test(1, 2);
	test(2, 1);
	test(2, 3);
	test(1, 7);
	test(1, 2007);
	test(-50, 8);
	test(1, INT32_MIN);
}