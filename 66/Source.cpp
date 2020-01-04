#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
	vector<size_t> plusOne(vector<size_t>& digits) {
		vector<size_t> result;
		recursivePO(digits, result, digits.size() - 1, true);
		return result;
	}

	void recursivePO(const vector<size_t>& digits, vector<size_t>& ans, size_t pos, bool carry) {
		if (pos == -1) {
			if (carry)
				ans.push_back(1);
			return;
		}
		if (carry) {
			size_t add = digits[pos] + 1;

			recursivePO(digits, ans, pos - 1, add > 9);
			ans.push_back(add % 10);
		}
		else {
			recursivePO(digits, ans, pos - 1, false);
			ans.push_back(digits[pos]);
		}
	}

};

std::ostream& operator<<(std::ostream& os, const vector<size_t>& v) {
	if (v.size() == 0) return os << "[]";
	auto i = v.begin();
	os << "[" << *i;
	i++;
	while (i != v.end()) {
		os << "," << *i;
		i++;
	}
	return os << "]";
}

size_t main() {
	vector<size_t> t1{ 1,2,3 };
	vector<size_t> t2{ 4,3,2,1 };
	vector<size_t> t3{ 9,9,9 };
	Solution s;
	std::cout << s.plusOne(t1) << std::endl;
	std::cout << s.plusOne(t2) << std::endl;
	std::cout << s.plusOne(t3) << std::endl;
}