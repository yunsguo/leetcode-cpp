#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Solution {
public:

	Solution() {
		if (cache.size() == 0)cache.push_back("1");
	}

	static vector<string> cache;

	string recursive_cas(size_t n) {
		if (cache.size() >= (size_t)n)
			return cache[n - 1];
		string str = recursive_cas(n - 1);
		char c = str[0];
		size_t t = 1;
		string result = "";
		for (size_t i = 1; i < str.length(); i++) {
			if (str[i] == c) t++;
			else {
				result += std::to_string(t) + c;
				t = 1;
				c = str[i];
			}
		}
		result += std::to_string(t) + c;
		cache.push_back(result);
		return result;
	}

	string countAndSay(size_t n) {
		return recursive_cas(n);
	}
};

vector<string> Solution::cache;

size_t main() {
	Solution s;
	std::cout << s.countAndSay(1) << std::endl;;
	std::cout << s.countAndSay(2) << std::endl;;
	std::cout << s.countAndSay(3) << std::endl;;
	std::cout << s.countAndSay(4) << std::endl;;
	std::cout << s.countAndSay(5) << std::endl;;

	for (auto c : s.cache)
		std::cout << c << std::endl;
}