#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() <= 1) return s;
		max = 0;
		for (size_t i = 0; i < s.size() - 1; i++) {
			extent(s,i,i+1);
			extent(s, i, i + 2);
		}
		return s.substr(p_, max);
	}
private:
	void extent(string& str, size_t j, size_t k) {
		while (j >= 0 && k < (size_t)str.size() && str[j] == str[k])
		{
			j--; k++;
		}
		auto l = k - j - 1;
		if (max < l) {
			p_ = j + 1;
			max = l;
		}
	}
	unordered_set<size_t> single_cores;
	unordered_set<size_t> double_cores;
	size_t p_;
	size_t max;
};

size_t main()
{
	Solution s;
	s.longestPalindrome("ccd");
}