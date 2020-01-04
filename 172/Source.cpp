#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <type_traits>

using namespace std;

size_t reminder(size_t m)
{
	if (m == 0) return 0;
	auto r = m % 10;
	if (r != 0)
		return r;
	return reminder(m / 10);
}

size_t zeros(size_t m)
{
	if (m == 0) return 0;
	if (m % 10 != 0)
		return 0;
	return zeros(m / 10) + 1;
}

class Solution {
public:
	size_t trailingZeroes(size_t n) {
		if (table().count(n) != 0) return table().at(n).second;
		if (n <= 1) {
			table()[n] = { 1,0 };
			set_max(n);
			return 0;
		}
		auto last = max();
		if (last == 0) trailingZeroes(0);
		auto p = table().at(last);
		while (true) {
			auto m = (last + 1) * p.first;
			size_t result = p.second;
			if (m % 10 == 0) result += zeros(m);
			p = { reminder(m),result };
			table()[(last + 1)] = p;
			if (last == n - 1) return result;
			last++;
		}
	}

	static unordered_map<size_t, pair<size_t, size_t>>& table()
	{
		static unordered_map<size_t, pair<size_t, size_t>> t;
		return t;
	}

	static size_t& max()
	{
		static size_t m=0;
		return m;
	}

	static void set_max(size_t n) { if (max() < n) max() = n; }
};

size_t main()
{
	Solution s;
	cout << s.trailingZeroes(1808548329) << endl;
}