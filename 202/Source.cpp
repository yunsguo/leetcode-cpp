#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool isHappy(size_t n) {
		unordered_map<size_t, bool>& t = table();
		if (t.count(n) != 0) return t.at(n);
		unordered_set<size_t> marked{ n };
		bool r = is_happy_impl(n, marked);
		for (size_t n : marked)
			t[n] = r;
		return r;
	}
private:
	static unordered_map<size_t, bool>& table() {
		static unordered_map<size_t, bool> t{ {1,true} };
		return t;
	}

	static size_t cal_ssod(size_t n) {
		size_t ssod = 0;
		while (n != 0)
		{
			size_t d = n % 10;
			ssod += d * d;
			n /= 10;
		}
		return ssod;
	}

	bool is_happy_impl(size_t n, unordered_set<size_t>& set) {
		auto ssod = cal_ssod(n);
		unordered_map<size_t, bool>& t = table();
		if (t.count(ssod) != 0) return t.at(ssod);
		if (set.count(ssod) != 0) {
			return false;
		}
		set.insert(ssod);
		return is_happy_impl(ssod, set);
	}
};

size_t main()
{
	Solution s;
	for (size_t i = 1; i < 100; i++)
		cout << i << ": " << (s.isHappy(i) ? "true" : "false") << endl;
}