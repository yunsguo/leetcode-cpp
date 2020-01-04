#include <string>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string ans;
		auto al = a.length();
		auto bl = b.length();
		if (al > bl)
			recursiveAB(a, b, ans, al - 1, bl - 1, false);
		else recursiveAB(b, a, ans, bl - 1, al - 1, false);
		return ans;
	}

	void recursiveAB(const string& a, const string&b, string& ans, size_t i, size_t j, bool carry) {
		if (i ==-1) { if (carry) ans += '1'; return; }
		char aa = a[i];
		char bb;
		if (j < 0) bb = '0';
		else bb = b[j];
		auto p = add(aa, bb, carry);
		recursiveAB(a, b, ans, i - 1, j - 1, p.first);
		ans += p.second;
	}

	static pair<bool, char> add(char a, char b, bool carry) {
		if (!carry) {
			if (a == '0') {
				if (b == '0')
					return { false,'0' };
				else return { false,'1' };
			}
			else {
				if (b == '0')
					return { false,'1' };
				else return { true,'0' };
			}
		}
		else {
			if (a == '0') {
				if (b == '0')
					return { false,'1' };
				else return{ true,'0' };
			}
			else {
				if (b == '0')
					return { true,'0' };
				else return { true,'1' };
			}
		}
	}
};

size_t main() {
	Solution s;
	std::cout << s.addBinary("11", "1") << std::endl;
	std::cout << s.addBinary("1010", "1011") << std::endl;
}