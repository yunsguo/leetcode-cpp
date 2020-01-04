#include <string>
#include <iostream>

using std::string;

class Solution {
public:
	size_t lengthOfLastWord(string s) {
		if (s == "") return 0;
		size_t i = s.length() - 1;
		while (i >= 0 && s[i] == ' ')
			i--;
		return recursiveLOLW(s, i);
	}

	size_t recursiveLOLW(const string& str, size_t i) {
		if (i < 0) return 0;
		if (str[i] == ' ') return 0;
		return 1 + recursiveLOLW(str, i - 1);
	}
};

size_t main() {
	Solution s;
	std::cout << s.lengthOfLastWord("Hello World") << std::endl;
	std::cout << s.lengthOfLastWord("") << std::endl;
	std::cout << s.lengthOfLastWord(" ") << std::endl;
}