#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	size_t titleToNumber(string s) {
		size_t r = s.back() - '@';
		s.pop_back();
		if (s.size() == 0) return r;
		return 26 * titleToNumber(s) + r;
	}
};

void display(string str)
{
	Solution s;
	std::cout << str << ": " << s.titleToNumber(str) << std::endl;
}
size_t main()
{
	display("A");
	display("AB");
	display("ZY");
}