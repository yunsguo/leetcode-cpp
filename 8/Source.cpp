#include <string>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
	size_t myAtoi(string str) {
		size_t start = 0;

		while (start < str.size()) {
			if (str[start] == ' ')
				start++;
			else break;
		}
		bool is_neg = false;
		char first = str[start];

		if (first == '-')
		{
			is_neg = true;
			start++;
		}
		else if (first == '+')
			start++;
		else if (!isdigit(first))
			return 0;

		while (str[start]=='0' && start < str.size())
			start++;

		size_t end = start;
		while (isdigit(str[end]) && end < str.size())
			end++;
		str = str.substr(start, end - start);
		if (str == "") return 0;
		if (str.size() <= 9)
		{
			auto d = toi(str);
			return is_neg ? -1 * d : d;
		}
		auto ld = str.front() - '0';
		if (str.size() >= 11 || ld >= 3)
			return is_neg ? -1 * pmin - pld : pmax + pld;
		auto pld1 = ld * 1000000000;
		auto p_i = toi(str.substr(1));
		if (is_neg) {
			if (p_i <= pmin || ld<=1) return -1 * p_i - pld1;
			return -1 * pmin - pld;
		}
		if (p_i <= pmax || ld <= 1) return p_i + pld1;
		return pmax + pld;
	}

	size_t toi(const string&str) {
		size_t i = 0;
		for (size_t d = 0; d < str.size() - 1; d++)
		{
			i += str[d] - '0';
			i *= 10;
		}
		i += str.back() - '0';
		return i;
	}

	static const size_t pmin = 147483648;
	static const size_t pmax = 147483647;
	static const size_t pld = 2000000000;
};

size_t main()
{
	Solution s;
	cout << s.myAtoi("42") << endl;

	cout << s.myAtoi("   -42") << endl;

	cout << s.myAtoi("4193 with words") << endl;

	cout << s.myAtoi("words and 987") << endl;

	cout << s.myAtoi("-91283472332") << endl;

	cout << s.myAtoi("+1") << endl;

	cout << s.myAtoi("  0000000000012345678") << endl;

	cout << s.myAtoi("+-2") << endl;

	cout << s.myAtoi("-5-") << endl;

	cout << s.myAtoi("-57") << endl;
	
	cout << s.myAtoi(" 1175109307q7") << endl;


}